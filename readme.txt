fix.c takes a file with n amount of rows and checks if they meet a desired criteria
In the example, each row meeting the criteria contains a "-" (dash) character as the first 
character in the first column. Each row meeting the criteria also contains exactly 15 tabs, so 16 columns of data.
These two criteria are passed as command line arguments and run as: ./<program name> 15 -

The file takes those rows which meet the criteria and writes them into a "good" file named goodfile.txt
For all rows that do not match the given criteria, they get written into badfile.txt

The need for the program arose from having to quickly filter out rows of data for analysis.
The program does not fix any rows that are considered broken, i.e. not meeting the criteria, 
but some columns in the dataset contain extra carriage returns and thus can not be directly
read into a dataframe in e.g. Excel or an R or Pandas dataframe. The program merely filters these out.

It is possible to modify the program so that it actually fixes rows that do not meet the given criteria.
I think the approach would be to keep reading characters in one at a time and replacing carriage returns as you go until
you have met the desired tabcount. Then you would write that line somewhere and progress to the next one.
