getline(char-array,n,delimiter);
input:apple
cin.getline(a,5);
output:appl\0
It extracts n-1 characters and puts \0 at nth position. (n-1) chars+ \0 is stored in the char-array.
If delimiter is met, it stores till the delimiter(excluded). and then \0 is put after it and stored. No more chars are read

cin >> a;
stores char in a with \0.
Input: apple
for(int i=0; i<6; i++)
cout << a[i];
Output:apple\0 //single space is seen after 'e' because of \0. Junk values follow.

gets(a) stdio.h
stores the whole string with \0
