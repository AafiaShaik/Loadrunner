Fileoperations_write()
{
	
	long fp;
	
            fp= fopen("D:\\Fileoperations\\correlationstrings1.txt","a");
            lr_save_datetime("%d-%m-%y",DATE_NOW ,"datetime");
            fprintf(fp,"Iteration Number is %s \n",lr_eval_string("{prmIterationNumber}"));
            fprintf(fp,"Todays date is %s \n",lr_eval_string("{datetime}"));
            lr_save_datetime("%d-%m-%y",DATE_NOW + ONE_DAY ,"datetime1");
            fprintf(fp,"date after one day  is %s \n",lr_eval_string("{datetime1}"));
            fclose(fp);
            
            
            
	return 0;
}
