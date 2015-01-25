import sys
import imaplib
import getpass
import email
import email.header
import datetime
import os
import re
import smtplib

detach_dir = "."
EMAIL_ACCOUNT = ""
EMAIL_FOLDER = ""
EMAIL_PASS = ""
list_response_pattern = re.compile(r'\((?P<flags>.*?)\) "(?P<delimiter>.*)" (?P<name>.*)')

def prompt(prompt):
    return raw_input(prompt).strip()



def parse_list_response(line):
    flags, delimiter, mailbox_name = list_response_pattern.match(line).groups()
    mailbox_name = mailbox_name.strip('"')
    return (flags, delimiter, mailbox_name)




def get_mailbox(EMAIL_ACCOUNT, EMAIL_PASS,  M,  EMAIL_FOLDER):
    
    rv, data = M.search(None, "ALL")
    if rv != 'OK':
        print "No messages found!"
        return
    if(os.path.exists("MAIL/"+EMAIL_FOLDER)):
        print "Folder Exists"
    else:
        os.makedirs("MAIL/"+EMAIL_FOLDER)
    
    detach_dir="."
    filename = "temp.txt"
    att_path1 = os.path.join(detach_dir,filename)
    fptemp = open(att_path1, 'wb')
    fptemp.write(EMAIL_FOLDER)
    fptemp.close()

    detach_dir="MAIL/"+EMAIL_FOLDER+"/"
    
    #os.makedirs(EMAIL_FOLDER+"/MAILS")
 
    for num in data[0].split():
        rv, data = M.fetch(num, '(RFC822)')
        if rv != 'OK':
            print "ERROR getting message", num
            return
        msg = email.message_from_string(data[0][1])
        xyz = msg
        body = "OOPS!! No Body"
        if xyz.get_content_maintype() == 'multipart': 
            for part in xyz.walk():       
                if part.get_content_type() == "text/plain":
                    body = part.get_payload(decode=True)
        else:
            for part in xyz.walk():
                body = part.get_payload(decode=True)
        decode = email.header.decode_header(msg['Subject'])[0]
        subject = unicode(decode[0])
        filename = EMAIL_FOLDER+num+".txt"
        
        att_path = os.path.join(detach_dir, filename)
        
        print ("Accessing..")
        fp = open(att_path, 'wb')

        fp.write("Subject : ")
        fp.write(subject)
        fp.write("\nDate : ")
        fp.write( msg['Date'])
        fp.write("\nFrom : ")
        fp.write( msg['From'])
        fp.write("\n\nMessage : \n")
        fp.write( body)

        fp.close()
        

    major(EMAIL_ACCOUNT, EMAIL_PASS, M)


def main():

    print("###########################################################################")
    print("#                                                                         #")
    print("#                                                                         #")
    print("#                                                                         #")
    print("#                                                                         #")
    print("#                   Welcome to the SPCF :V-1.0.0                          #")
    print("#                         Spam Classifier                                 #")
    print("#                     By - Asim Krishna Prasad                            #")
    print("#                    http://github.com/pakhandi                           #")
    print("#                       http://bugecode.com                               #")
    print("#                                                                         #")
    print("#                                                                         #")
    print("#                                                                         #")
    print("#                                                                         #")
    print("###########################################################################")
    print ""
    print ""
    print("Connecting to Gmail .. .. ")
    M = imaplib.IMAP4_SSL('imap.gmail.com')

    try:
        EMAIL_ACCOUNT = prompt("Username : ")
        EMAIL_PASS = getpass.getpass()
        rv, data = M.login(EMAIL_ACCOUNT,EMAIL_PASS)
    except imaplib.IMAP4.error:
        print "LOGIN FAILED!!! "
        sys.exit(1)

    print rv, data

    major(EMAIL_ACCOUNT,EMAIL_PASS, M)

def major(EMAIL_ACCOUNT, EMAIL_PASS, M):
    print("\n\n\n################################")
    print("MENU : ")
    print("1: Sync Mail-Boxes")
    print("2: EXIT")
    print("Enter your choice : \n\n")

    dec = raw_input()

    if dec == '2':
        sys.exit(0);

    if dec == '1':
        
        rv, mailboxes = M.list()
        if rv == 'OK':
            print "Mailboxes:"
            for line in mailboxes:
                print 'Server response:', line
                flags, delimiter, mailbox_name = parse_list_response(line)
                #print 'Parsed response:', (flags, delimiter, mailbox_name)

        print "Enter the mail-folder you want to sync : "
        EMAIL_FOLDER = raw_input();
         
        rv, data = M.select(EMAIL_FOLDER)
        if rv == 'OK':
            print "Getting mailbox...\n"
            get_mailbox(EMAIL_ACCOUNT, EMAIL_PASS, M, EMAIL_FOLDER)
            M.close()
        else:
            print "ERROR: Unable to open mailbox ", rv

    else:
        print "Wrong Selection"
        major(EMAIL_ACCOUNT,EMAIL_PASS, M)


     
    M.logout()

if __name__ == "__main__":
    main()
