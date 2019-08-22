Fileoperations()
{
	/*
	 int  fp,i,j;


        //LPCSTR Rows;
        char new_dir[] = "C:\\anaz";

                //Create a directory under root called anaz and make it the current dir

                if (mkdir(new_dir)==1)

                {

                lr_output_message ("Directory already created %s ", new_dir);

                goto FILEOPEN;

                return -1;

                }

                        //Rows=lr_get_attrib_string("rows");

                        //j=atoi(Rows);

                         FILEOPEN:

                                        //fp = fopen("c:\\anaz\\my_file{FileName}.csv","w+");
                 fp=fopen(lr_eval_string
("c:\\anaz\\my_file{FileName}.csv"), "w+");
                                                
                                        if (fp==0)

                                        {

                                        lr_error_message ("Cannot open file, it is already opened %s", fp);

                                        return -1;

                                        }
                                                fprintf(fp,"FirstName,LastName,Email,Salutation,title,street,City,State,Country,zip,phone,Department,Custom1,Custom2,Cost
Center\n");
                                                        for(i=0;i<=10;i++)
                                                        {
                                                        
                                                        fprintf(fp,"%s",lr_eval_string("{FN},{SN},{FN}...@may.com,{SAL},{Title},{Street},{City},{State},{Country},{ZIP},{Phone},DEV,cust1,cust2,cost1\n"));
                                                        }
                                        fclose(fp);

                                        //char fp= lr_eval_string("c:\\anaz\\my_file{FileName}.csv");

                        /*if (remove(lr_eval_string ("c:\\anaz\\my_file{FileName}.csv")) == 0)

                                        lr_output_message (lr_eval_string("Removed new file
c:\\anaz\\my_file{FileName}.csv"));*/

                                //else

                                        //lr_output_message ("Unable to remove the file %d error %d", fp);

                                /*if (rmdir(new_dir) == 0)

                                        lr_output_message ("Removed new directory %s", new_dir);

                                else

                                        lr_output_message ("Unable to remove %s error %d", new_dir);*/


	
	return 0;
}
