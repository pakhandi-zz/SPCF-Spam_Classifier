echo "Taking mails .. .."
find *.txt > listfiles.txt

mkdir "SPAM_MAILS"
mkdir "NONSPAM_MAILS"

i=1
limit=$(wc -l listfiles.txt | cut -d " " -f 1)
echo "Starting Classification of mails .. .."
while [ $i -le $limit ]
do
	filename=$(head -$i listfiles.txt | tail -1)
	./classify < $filename
	a=$(head -1 classified.txt | cut -d " " -f 1)
	b=$(head -1 classified.txt | cut -d " " -f 2)
	echo "Processing .. .."
	if [ $a -gt $b ]:
	then
		cp $filename "SPAM_MAILS"
	else
		cp $filename "NONSPAM_MAILS"
	fi
	rm "classified.txt"
	i=$(expr $i + 1)
done

echo "Cleaning up"

rm "SPAM_MAILS/spam_dict.txt"
rm "NONSPAM_MAILS/nonspam_dict.txt"
rm "listfiles.txt"


