./download_mail
if [ -f "failure.txt" ]:
then
		rm "failure.txt"
		exit 0
fi
echo "Entering the folder .. .."
folder=$(head -1 "temp.txt")
folder="MAIL/"$folder"/"
echo "Transferring necessary files .. .."
cp "sc.sh" $folder
cp "classify" $folder
cp "spam_dict.txt" $folder
cp "nonspam_dict.txt" $folder
echo "Waiting to start .. .."
(cd $folder; sh "sc.sh")
echo "Finishing .. .. "
rm "temp.txt"
echo "DONE!!"

