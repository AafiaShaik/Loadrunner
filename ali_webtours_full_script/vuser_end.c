vuser_end()
{

	lr_think_time(10);
	lr_start_transaction("webtours_ticketbooking_07_logout");
	Extended_Log_On();

	web_reg_find("Text=Web Tours","savecount=s7", 
		LAST);


	web_url("welcome.pl_2", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
	if(atoi(lr_eval_string("{s7}"))>0)
	{
		lr_output_message("page7 pass");
	lr_end_transaction("webtours_ticketbooking_07_logout",LR_PASS);	
	}
else
{
	lr_error_message("page7 fail");
	lr_end_transaction("webtours_ticketbooking_07_logout",LR_FAIL);
	lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE,LR_FAIL);
}
	
Extended_Log_On();
	return 0;
}