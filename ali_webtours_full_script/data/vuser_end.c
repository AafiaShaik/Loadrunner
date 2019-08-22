vuser_end()
{

	lr_start_transaction("logout");

	web_reg_find("Text=Web Tours", 
		LAST);

	lr_think_time(22);

	web_url("welcome.pl_2", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	return 0;
}