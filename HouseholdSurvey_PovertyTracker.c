/****
* Name:					Ivan Belov
* Student ID:			T00637195
* Assignment#3:			Household Survey - Function use with pointers
* Due Date:				February 6, 2020
* Program Description:	Apart from the functionality required for the
*						Assignment #1:
*							accepting several arrays of provided pre - organized data,
*							calculate the household average, and figure out the house hold rating.
*						Assignment#2 implements all of the above mentioned functionality
*							into separate functions.
*							1st Function - averageIncomeCalc - calculating averageIncome of all households with basic mathematical equations.
*							2nd Function - povertyPercentageCalc - calculating poverty percentage of households that have monetary issues.
*							3rd Function - povertyScoreCalc - calculating a poverty rating score by processing given financial data for each household.
*							4th Function - AssignmentTwo - performs the data processing and data output to the main screen.
*						Assignment#3 introduces pointers into the mix where appropriatly.
*							averageIncomeCalc function accept a pointer to the amount of total families, pointer to the array with the
*								household income breakdown.
*							povertyPercentageCalc function accepts a pointer to the amount of total families, pointer to the array with the
*								number of family members per household, pointer to the array with the household income breakdown.
*							povertyScoreCalc accepts an int variable holding the size of a given family. 
****/

    #include <stdio.h>

	// calculating the average income of households provided
	int averageIncomeCalc(int * membersNumberPointer, int * incomePointer);

	// calculating poor household percentage of all households
	double povertyPercentageCalc(int * membersNumberPointer, unsigned char * membersPointer, int * incomePointer);

	// calculating poverty level for a given household
	int povertyScoreCalc(int familySizeP);

	// calculating the Assignment#1 output through
	// a function with the use of pointers
	void assignmentTwo(unsigned char * membersPointer, int * incomePointer, char **commentsPointer , char **householdsPointer,
		int *membersNumberPointer, char **tabNamesPointer);

    // Beginning of the application
    int main()
    {
    	
	// Variable to hold average income calculation
	int averageIncome = 0;

	// Variable below helps to determine
	// poverty level of a given household
	long int povertyLevel = 0;

	// Variable to hold poverty level percentage
	float povertyPercentage = 0;

	// Supplementary One dimensional array created to facilitate formatted
	// data output
	char *tabNames[] = {"Household","Income","Members",
					"Comments"};
	
	// tabNamesPointer points towards the names of tabs
	// to used used during the data output process				
	char **tabNamesPointer = tabNames;

	// Unsigned char recordNumber is used to verify a number
	// of members array data records
	int membersNumber = 0;

	// First One dimential array holding family names
	char *households[] = {"Armstrong","Burns","Cousins",
					"Duggan","Evans","Field","Garnett",
					"Hadfield","Johnston","Lovett",
					"McDonald","Peterson","Singh"};
	
	//householdsPOinter points towards an array of arrays
	// with family names for each household
	char ** householdsPointer = households;

	// Second One dimensional array holding household's income
	long int income[] = {25295,35178,66711,10455,
					28943,43226,30869,21143,
					26444,33777,17551,41323,
					39117};

	// Assigning income[] to the pointer ( constant )
	int * incomePointer = income;

	// Third one dimensional array holding
	unsigned char members[] = {7,3,5,1,3,3,4,5,3,
							4,1,4,2};
	
	// membersPointer point towards the array of family members of each houseld
	unsigned char * membersPointer = members;
	
	// Accepting array size for verification purposes
	// The idea behind this calculation was picked up at
	// https://stackoverflow.com/questions/8759008/count-elements-in-array-in-c
	membersNumber = sizeof(members);
	
	// membersNumberPointer points to the amount of all households
	// currently present
	int * membersNumberPointer = & membersNumber;

	// Creating One dimensional array to hold
	// poverty comments with the size available data records
	char *comments[membersNumber];
	
	// pointer to the array of pointers holding rating values for
	// households
	char ** commentsPointer = *comments;
	
	// Calculating average income of all households
	averageIncome = averageIncomeCalc(membersNumberPointer, incomePointer);
			
	// Executing output from Assignment One
	assignmentTwo(membersPointer, incomePointer, commentsPointer, householdsPointer, membersNumberPointer, tabNamesPointer);

	// Return of the main()
	return 0;
    } // End of main()

    // calculating the average income of households provided
    int averageIncomeCalc(int * membersNumberPointer, int *incomePointer)
    {
    
    // below variable afacilitates average income calculation 
	int averageIncomeP = 0;
	
	// for loop needs a calculation of average to have proper star allocation
	// below calculation does performs it separately from another for loop
	// that is placed to calculate the star rating of each household
	for (int count = 0; count < *membersNumberPointer; count++)
	{
		// Prepairing to assemble a pool of income data
		averageIncomeP += *(incomePointer+count);
	}
	// returning final calculated value of average income
	return (averageIncomeP / *membersNumberPointer);
    } // End of averageIncomeCalc

    // calculating poor household percentage.
    // confusing assignmnet requirements.
    double povertyPercentageCalc(int * membersNumberPointer, unsigned char *membersPointer, int *incomePointer)
    {
    	// facilitates with overall poverty calculation
    	double overallPoverty = 0;
    	
    	// counts an amount of poor households
    	int poorHouseholdCountP = 0;
    	
    	// below for loop depends on the number of households,
    	// number of households value is provided through membersNumberPointer
    	// membersPointer provides a pointer to an array holding amount of family members
    	// each household has.
    	// incomePointer is apointer towards 
        for (int count = 0; count < *membersNumberPointer; count++)
        {
            if ( ( *(incomePointer+count) - povertyScoreCalc( *(membersPointer+count) ) ) < 0 )
            {
                poorHouseholdCountP++;
            }
        }
    
    // calculating and returng poor household percentage
	return overallPoverty = ((poorHouseholdCountP * 100.00)/ *membersNumberPointer);
	
    } // End of povertyPercentageCalc

    // calculating poverty level for a given household
    int povertyScoreCalc(int familySizeP)
    {    	
		return (18000 + 1500*(familySizeP-2));
    } // End of povertyScoreCalc

	// calculating the Assignment#1 output through
	// a function
    void assignmentTwo(unsigned char * membersPointer, int * incomePointer, char **commentsPointer , char **householdsPointer,
		int *membersNumberPointer, char **tabNamesPointer)
    {
    // Idea for below code has been compiled by Ivan Belov
	// based on multiple sources such:
	// https://overiq.com/c-programming-101/one-dimensional-array-in-c/
	// https://overiq.com/c-programming-101/array-of-strings-in-c/
	// https://stackoverflow.com/questions/32315569/how-can-i-print-multiple-character-with-one-printf
	// and
	// https://stackoverflow.com/questions/1088622/how-do-i-create-an-array-of-strings-in-c
	// printing the tabs for the data table
	printf(" \n %-13s %s %8s %10s", *(tabNamesPointer), *(tabNamesPointer + 1), *(tabNamesPointer + 2), *(tabNamesPointer + 3));

	// Partial idea behind formatting
	// was picked up here:
	// https://www.codingunit.com/printf-format-specifiers-format-conversions-and-formatted-output
	for (int count = 0; count < *membersNumberPointer; count++)
	{
		int familyAvgInc = averageIncomeCalc ( membersNumberPointer, incomePointer );
		int familyPovScore = povertyScoreCalc( *(membersPointer + count));
		
	// below calculations are implemented based on Wayne B. solution.
	// He told me to do it this way.
	// High Income
	if ( ( *( incomePointer+count) ) > familyAvgInc  )
	{
		if ( *(incomePointer + count ) > ( familyAvgInc + 10000 ) )
		{
			commentsPointer = &"*";
		}
		else
		{
			commentsPointer = &"**";
		}
	} // Average Income
	else if ( ( *(incomePointer + count) ) < familyPovScore )
	{
		if ( ( *(incomePointer + count) ) < ( familyPovScore - 5000 ) )
		{
			commentsPointer = &"****";
		}
		else
		{
			commentsPointer = &"***";
		}
	} // Average Income (indednt done for printing purposes)
	else
	{
		commentsPointer = &" ";
	} // this is done for printing purposes
	// Printing formatted data

    // Based on a suggestion from Wayne B.
	printf(" \n %-13s %li \t %hhu \t %s ", *( householdsPointer + count ) , *( incomePointer + count ), *( membersPointer + count ), commentsPointer );
	
	// advance the pointer to comments / rating one step ahead
	commentsPointer++;
	
    } // End of the loop to output multiple array data

	// Four statements below are used
	// to print out a legend
	printf(" \n \n %s\t %s","*"," - Very High Income (income is more than $10,000 above the average)");
	printf("\n %s\t %s","**"," - Above Average Income");
	printf("\n %s\t %s","***"," - Income is below the Poverty Level");
	printf("\n %s\t %s \n","****"," - Extreme Poverty (more than $5,000 below the poverty level)");
	// Printing average household income
	printf("\n %s%.d.\n","The average income of the households surveyed is $", averageIncomeCalc(membersNumberPointer, incomePointer));
	// Printing poor household percentage
	// I thought that calculating household poverty level,
	// and then on the 13th iteration is to calculate and change a variable poorHouseholdPercentage might do.
	// but the variable would either not change our be outputted.
	// vague requirements.
	// function call was previously in the below statement
	// but was changed due to assignment requirements.
	printf("\n %s%1.1f%%","The percentage of households below the poverty level is ", povertyPercentageCalc(membersNumberPointer, membersPointer, incomePointer));
    } // End of AssignmentTwo
