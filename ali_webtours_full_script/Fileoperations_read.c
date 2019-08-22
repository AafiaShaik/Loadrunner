Fileoperations_read()
{
	/*-------------------------------------------------------------------
	//Read data in a file as string wise using common separator
	
	char *file1="D:\\Fileoperations\\patientdetails.csv";
	
	long filename1;
char s1[100],s2[100],s3[100],s4[100];
int d;
//filename1=fopen(file1,"w");
//fprintf(filename1,"%s","Welcome To Load Runner performance testing version 1");
filename1=fopen(file1,"r");
fscanf(filename1,"%s1",&s1);
fscanf(filename1,"%s2",&s2);
fscanf(filename1,"%s3",&s3);
fscanf(filename1,"%s4",&s4);
fscanf(filename1,"%d",&d);
lr_output_message("%s %s %s %s ",&s1,&s2,&s3,&s4);
lr_output_message("%d ",&d);
fclose(filename1);
*/
//------------------------------------------------------------------------------
//Read data in a file as line wise 

char *file1 = "D:\\Fileoperations\\correlationstrings2.txt";
long filename1;
char temp[100];
filename1=fopen(file1,"w");
fprintf(filename1,"%s","Welcome To Load Runner performance testing version 1");
filename1=fopen(file1,"r");
fgets(temp,200,filename1);
fclose(filename1);
return 0;






	lr_convert_double_to_double("srcparam", "strin", "int");

	lr_debug_message(LR_MSG_CLASS_BRIEF_LOG, "gggg");

	


}
