Action()
{
	//declarations
	
	int a,b,c,i,d,newint,q,w,e,r,t,y,u;
	char *temp,*temp1,*token,*temp2;
	long testfile;
	char *file="D:\\Fileoperations\\correlationstrings.txt";
	char *ip;
	char *ip1;
	
	//returns the name of the machine which is running the script
	lr_get_host_name(); 
	//returns controller name or tuning machine name
	lr_get_master_host_name();
	
	//lr_get_transaction_duration();

	ip = lr_get_vuser_ip();

if (ip)

     lr_output_message("The IP address is %s", ip);

else
{
     lr_output_message("IP spoofing disabled");
}
	lr_output_message("Vuser IP -> %s", lr_get_vuser_ip());
	lr_vuser_status_message("Vuser IP -> %s", lr_get_vuser_ip());
	lr_output_message("Current iteration #: %s", lr_eval_string("{prmIterationNumber}"));
lr_output_message("Current iteration #: %s", lr_eval_string("{Vuserid}"));

	//increase the size of correlation string length
	web_set_max_html_param_len("9999");
	
	//transaction(applicationname_scenarioname_pagenum_pagename)
	
	lr_start_transaction("webtours_ticketbooking_01_welcomepage"); 
	
	//textverification function 
	
	web_reg_find("Text=Web Tours","savecount=s1",
		LAST);
	
	//correlation function
	//correlation string length value is 256 bytes
	//="userSession" value="115908.53835561fQzcAtfpttVzzzzHDfHHcpcHczf"/>
	//<input type="hidden" name="userSession" value="115908.53835561fQzcAtfpttVzzzzHDfHHcpcHczf"/>
	
//	web_reg_save_param("sessionid",
//	                   "LB/IC=name=\"userSession\" value=\"",
//	                   "RB/IC=\"/>",
//	                   "ORD=all",
//	                   "Notfound=Warning",
//	                   LAST);
	                   
	lr_get_vuser_ip();
	
	//convert html to url to avoid space in between the correlation string
	
//	web_convert_param("InputParam",
//					  "sourcestring=115909.7269&3#3 98+1f Qzc%VAz@pfHQVzzzHDfHHcpzDQtHf",	                  
//	                  "SourceEncoding=HTML",
//           			  "TargetEncoding=URL", 
//           			  LAST);
	
	//<input type="hidden" name="userSession" value="115908.53835561fQzcAtfpttVzzzzHDfHHcpcHczf"/>
	//<input type=hidden name=userSession value=117918.721020656zAzftttpcVcfDzDQcpzzfcHf>
	web_reg_save_param("sessionid",
	                   "LB/IC=name=userSession value=",
	                   "RB/IC=>",
	                   "ORD=all",
	                   LAST);
		
	
	//get method function

	web_url("webtours", 
		"URL=http://127.0.0.1:1080/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	//file write operation
	
//	testfile=fopen(file,"a");
// 
//	fprintf(testfile,"%s\n",lr_eval_string("{sessionid}"));
//	fprintf(testfile,"%s\n","welcome to loadrunner");
//	fclose(testfile);
	
	// error handling for savecount
	
	/*if(atoi(lr_eval_string("{s1}"))>0)
	{
		lr_output_message("welcomepage is passed");
		lr_end_transaction("webtours_ticketbooking_01_welcomepage", LR_PASS);
	}
	else
	{
		lr_error_message("welcomepage is failed");
		lr_end_transaction("webtours_ticketbooking_01_welcomepage", LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}*/
	q=web_get_int_property(HTTP_INFO_RETURN_CODE);
	lr_output_message("%d",q);
	
	if(q==200)
	{
		
		lr_output_message("welcome page is passed");
		lr_end_transaction("webtours_ticketbooking_01_welcomepage", LR_PASS);
	}
	else
	{
		lr_error_message("welcome page is failed");
		lr_end_transaction("webtours_ticketbooking_01_welcomepage", LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	//------------------------------------------------------------------------------------------------------------

	//web_set_sockets_option("SSL_VERSION", "TLS1.1");
	lr_think_time(10);
	lr_start_transaction("webtours_ticketbooking_02_login");
	
	
	//rendezvous point to create stress for that functionality
	//lr_rendezvous("login");

	web_reg_find("Text=Web Tours","savecount=s2",LAST);
	
	//post method function
	//now we are going to apply log message manualy by disabling log option in runtime settings (result will be collected in out.txt path in same saved path)
	
	Extended_Log_On();

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={sessionid}", ENDITEM, 
		"Name=username", "Value={username}", ENDITEM, 	//parametrization of username
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=45", ENDITEM, 
		"Name=login.y", "Value=5", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);
	Extended_Log_On();
	
	//timestamp for unique number
	
	web_save_timestamp_param("timestamp",LAST);
	lr_output_message("timestamp is %d",lr_eval_string("{timestamp}"));
	
	//datetime function
	
	lr_save_datetime("%c",DATE_NOW,"Date");
	lr_output_message(lr_eval_string("{Date}"));
	
	lr_save_datetime("%c",DATE_NOW+ONE_DAY,"OneDayAdvanceDate");
	lr_output_message(lr_eval_string("{OneDayAdvanceDate}"));
	
	lr_save_datetime("%c",TIME_NOW,"TimeNow");
	lr_output_message(lr_eval_string("{TimeNow}"));
	
	lr_save_datetime("%c",TIME_NOW+ONE_HOUR,"TimeNowPlusOneHour");
	lr_output_message(lr_eval_string("{TimeNowPlusOneHour}"));
	
	//error handling for status code
	                  
	w=web_get_int_property(HTTP_INFO_RETURN_CODE);
	lr_output_message("%d",w);
	
	if(w==200)
	{
		
		lr_output_message("welcome page is passed");
		lr_end_transaction("webtours_ticketbooking_02_login", LR_PASS);
	}
	else
	{
		lr_error_message("welcome page is failed");
		lr_end_transaction("webtours_ticketbooking_02_login", LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
		lr_think_time(10);
//----------------------------------------------------------------------------------------------------------------------------------
	lr_start_transaction("webtours_ticketbooking_03_flights");

	web_reg_find("Text=Web Tours","savecount=s3",
		LAST);
	
	//<option selected="selected" value="Denver">Denver</option>
	//<option value="Frankfurt">Frankfurt</option>
	
	web_reg_save_param("cities","lb=<option value=\"","rb=\">","ord=all",LAST);
	web_reg_save_param("denvercity","lb=<option selected=\"selected\" value=\"","rb=\">","ord=all",LAST);
	
	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	//select a random variable
	
	d=rand()%9+1;
	temp=lr_paramarr_idx("cities",d);
	lr_save_string(temp,"newdepcity");
	
random:
	
	d=rand()%9+10;
	temp1=lr_paramarr_idx("cities",d);
	lr_save_string(temp1,"newarrcity");

	//string comparision
	
	if(strcmp(temp,temp1)==0)
		
		goto random;
	
	//string tokeniser
	
	temp2=lr_paramarr_idx("cities",6);
	token=(char *)strtok(temp2,"c");
	lr_save_string(token,"newstring");
	
	//array merging
	
	
	a=lr_paramarr_len("denvercity");
	b=lr_paramarr_len("cities");
	
	for(i=1;i<=a;i++)
	{
		c=b+i;
		lr_save_int(c,"newint");
		temp=lr_paramarr_idx("denvercity",i);
		lr_save_string(temp,lr_eval_string("cities_{newint}"));
	}
	
	/*if(atoi(lr_eval_string("{s3}"))>0)
	{
		lr_output_message("page3 pass");
	 lr_end_transaction("webtours_ticketbooking_03_flights",LR_PASS);	
	}
	else
	{
		lr_error_message("page3 fail");
		lr_end_transaction("webtours_ticketbooking_03_flights",LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}*/
	
	e=web_get_int_property(HTTP_INFO_RETURN_CODE);
	lr_output_message("%d",e);
	if(e==200)
	{
		lr_output_message("page 3 pass");
		lr_end_transaction("webtours_ticketbooking_03_flights",LR_PASS);	
	}
	else
	{
		lr_error_message("page 3 fail");
		lr_end_transaction("webtours_ticketbooking_03_flights",LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
//-----------------------------------------------------------------------------------------------------------------
		lr_think_time(10);

	lr_start_transaction("webtours_ticketbooking_04_findflight");

	web_reg_find("Text=Flight Selections","savecount=s4", 
		LAST);

	web_submit_data("reservations.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={newdepcity}", ENDITEM, 
		"Name=departDate", "Value={departdate}", ENDITEM, 	//parametrization of date
		"Name=arrive", "Value={newarrcity}", ENDITEM, 
		"Name=returnDate", "Value={arrivedate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=Aisle", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=26", ENDITEM, 
		"Name=findFlights.y", "Value=11", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);
	r=web_get_int_property(HTTP_INFO_RETURN_CODE);
		lr_output_message("%d",r);
	if(r==200)
	{
		lr_output_message("page 4 pass");
		lr_end_transaction("webtours_ticketbooking_04_findflight",LR_PASS);
	}
	else{
		lr_error_message("page 4 fail");
		lr_end_transaction("webtours_ticketbooking_04_findflight",LR_FAIL);
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	/*if(atoi(lr_eval_string("{s4}"))>0)
	{
		lr_output_message("page4  pass");
		lr_end_transaction("webtours_ticketbooking_04_findflight",LR_PASS);
	}
else
{
	lr_error_message("page4 fail");
	lr_end_transaction("webtours_ticketbooking_04_findflight",LR_FAIL);
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
}*/
//-------------------------------------------------------------------------------------------------------------------	
lr_think_time(10);
	lr_start_transaction("webtours_ticketbooking_05_selectflight");

	web_reg_find("Text=Flight Reservation", "savecount=s5",
		LAST);
	

	web_submit_data("reservations.pl_2", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=182;1153;05/07/2015", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=Aisle", ENDITEM, 
		"Name=reserveFlights.x", "Value=21", ENDITEM, 
		"Name=reserveFlights.y", "Value=10", ENDITEM, 
		LAST);
	t=web_get_int_property(HTTP_INFO_RETURN_CODE);
	lr_output_message("%d",t);
	if(t==200)
	{
		lr_output_message("page  5  pass");
		lr_end_transaction("webtours_ticketbooking_05_selectflight",LR_PASS);	
			}
	else
	{
		lr_error_message("page 5 fail");
		lr_end_transaction("webtours_ticketbooking_05_selectflight",LR_FAIL);	
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	
	/*if(atoi(lr_eval_string("{s5}"))>0)
	{
		lr_output_message("page5 pass");
	lr_end_transaction("webtours_ticketbooking_05_selectflight",LR_PASS);	
	}
else
{
	lr_error_message("page5 fail");
	lr_end_transaction("webtours_ticketbooking_05_selectflight",LR_FAIL);
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
}*/
	//--------------------------------------------------------------------------------------------------------------------------
lr_think_time(10);
	lr_start_transaction("webtours_ticketbooking_06_payment");

	web_reg_find("Text=Reservation Made!", "savecount=s6",
		LAST);

	

	web_submit_data("reservations.pl_3", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=34774545847689459645", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=saveCC", "Value=on", ENDITEM, 
		"Name=oldCCOption", "Value=on", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=seatPref", "Value=Aisle", ENDITEM, 
		"Name=outboundFlight", "Value=182;1153;05/07/2015", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=buyFlights.x", "Value=40", ENDITEM, 
		"Name=buyFlights.y", "Value=13", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);
	y=web_get_int_property(HTTP_INFO_RETURN_CODE);
	lr_output_message("%d",y);
	if(y==200)
	{
		lr_output_message("page 6 pass");
		
		lr_end_transaction("webtours_ticketbooking_06_payment",LR_PASS);	
		
	}
	else
	{
		lr_error_message("page  6 fail");
		lr_end_transaction("webtours_ticketbooking_06_payment",LR_FAIL);	
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
	}
	/*
	if(atoi(lr_eval_string("{s6}"))>0)
	{
		lr_output_message("page6 pass");
	lr_end_transaction("webtours_ticketbooking_06_payment",LR_PASS);	
	}
else
{
	lr_error_message("page7 fail");
	lr_end_transaction("webtours_ticketbooking_06_payment",LR_FAIL);
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
}*/
	
	return 0;
}
