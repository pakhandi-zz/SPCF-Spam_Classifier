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
cp "extract_words" $folder
echo "Waiting to start .. .."
(cd $folder; sh "sc.sh")
echo "Updating & Cleaning Dictionaries .. .."
./clean_dict < "spam_dict.txt" > "temp_dict.txt"
cat "temp_dict.txt" > "spam_dict.txt"
./clean_dict < "nonspam_dict.txt" > "temp_dict.txt"
cat "temp_dict.txt" > "nonspam_dict.txt"
echo "Finishing .. .. "
rm "temp.txt"
rm "temp_dict.txt"
echo "DONE!!"

