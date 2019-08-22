Action()
{

	lr_start_transaction("flights");

	web_reg_find("Text=Web Tours", 
		LAST);

	lr_think_time(21);

	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("flights",LR_AUTO);

	lr_start_transaction("findflight");

	web_reg_find("Text=Flight Selections", 
		LAST);

	lr_think_time(32);

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
		"Name=depart", "Value=Frankfurt", ENDITEM, 
		"Name=departDate", "Value=05/07/2015", ENDITEM, 
		"Name=arrive", "Value=Sydney", ENDITEM, 
		"Name=returnDate", "Value=05/08/2015", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=Aisle", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=26", ENDITEM, 
		"Name=findFlights.y", "Value=11", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_end_transaction("findflight",LR_AUTO);

	lr_start_transaction("selectflight");

	web_reg_find("Text=Flight Reservation", 
		LAST);

	lr_think_time(19);

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

	lr_end_transaction("selectflight",LR_AUTO);

	lr_start_transaction("payment");

	web_reg_find("Text=Reservation Made!", 
		LAST);

	lr_think_time(13);

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

	lr_end_transaction("payment",LR_AUTO);

	return 0;
}
