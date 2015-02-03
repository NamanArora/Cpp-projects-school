getline(char-array,n,delimiter);
input:apple
cin.getline(a,5);
output:appl\0
It extracts n-1 characters and puts \0 at nth position. (n-1) chars+ \0 is stored in the char-array.
If delimiter is met, it stores till the delimiter(included). but it discards the delimiter and puts \0.Storing stops here. next reading 
starts after the delimiter.
input: apple
cin.getline(a,20,'l'); 
appl<-pointer-> then app\0
cin.getline(a,20);
e\0

cin.get(char-array,n,delimiter)
same function as getline but 
when delimiter is met, it stops before that. next reading starts from the delimiter
input: apple
cin.get(a,20,'l');
a= app<-pointer->le

cin.get(a,20);
le\0


cin >> a;
stores char in a with \0.
Input: apple
for(int i=0; i<6; i++)
cout << a[i];
Output:apple\0 //single space is seen after 'e' because of \0. Junk values follow.

gets(a) stdio.h
stores the whole string with \0

