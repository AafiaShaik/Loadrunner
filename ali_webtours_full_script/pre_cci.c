# 1 "c:\\users\\administrator\\desktop\\ali_webtours_full_script\\\\combined_ali_webtours_full_script.c"
# 1 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h" 1
 
 












 











# 103 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"








































































	

 



















 
 
 
 
 


 
 
 
 
 
 














int     lr_start_transaction   (char * transaction_name);
int lr_start_sub_transaction          (char * transaction_name, char * trans_parent);
long lr_start_transaction_instance    (char * transaction_name, long parent_handle);
int   lr_start_cross_vuser_transaction		(char * transaction_name, char * trans_id_param); 



int     lr_end_transaction     (char * transaction_name, int status);
int lr_end_sub_transaction            (char * transaction_name, int status);
int lr_end_transaction_instance       (long transaction, int status);
int   lr_end_cross_vuser_transaction	(char * transaction_name, char * trans_id_param, int status);


 
typedef char* lr_uuid_t;
 



lr_uuid_t lr_generate_uuid();

 


int lr_generate_uuid_free(lr_uuid_t uuid);

 



int lr_generate_uuid_on_buf(lr_uuid_t buf);

   
# 266 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
int lr_start_distributed_transaction  (char * transaction_name, lr_uuid_t correlator, long timeout  );

   







int lr_end_distributed_transaction  (lr_uuid_t correlator, int status);


double lr_stop_transaction            (char * transaction_name);
double lr_stop_transaction_instance   (long parent_handle);


void lr_resume_transaction           (char * trans_name);
void lr_resume_transaction_instance  (long trans_handle);


int lr_update_transaction            (const char *trans_name);


 
void lr_wasted_time(long time);


 
int lr_set_transaction(const char *name, double duration, int status);
 
long lr_set_transaction_instance(const char *name, double duration, int status, long parent_handle);


int   lr_user_data_point                      (char *, double);
long lr_user_data_point_instance                   (char *, double, long);
 



int lr_user_data_point_ex(const char *dp_name, double value, int log_flag);
long lr_user_data_point_instance_ex(const char *dp_name, double value, long parent_handle, int log_flag);


int lr_transaction_add_info      (const char *trans_name, char *info);
int lr_transaction_instance_add_info   (long trans_handle, char *info);
int lr_dpoint_add_info           (const char *dpoint_name, char *info);
int lr_dpoint_instance_add_info        (long dpoint_handle, char *info);


double lr_get_transaction_duration       (char * trans_name);
double lr_get_trans_instance_duration    (long trans_handle);
double lr_get_transaction_think_time     (char * trans_name);
double lr_get_trans_instance_think_time  (long trans_handle);
double lr_get_transaction_wasted_time    (char * trans_name);
double lr_get_trans_instance_wasted_time (long trans_handle);
int    lr_get_transaction_status		 (char * trans_name);
int	   lr_get_trans_instance_status		 (long trans_handle);

 



int lr_set_transaction_status(int status);

 



int lr_set_transaction_status_by_name(int status, const char *trans_name);
int lr_set_transaction_instance_status(int status, long trans_handle);


typedef void* merc_timer_handle_t;
 

merc_timer_handle_t lr_start_timer();
double lr_end_timer(merc_timer_handle_t timer_handle);


 
 
 
 
 
 











 



int   lr_rendezvous  (char * rendezvous_name);
 




int   lr_rendezvous_ex (char * rendezvous_name);



 
 
 
 
 
char *lr_get_vuser_ip (void);
void   lr_whoami (int *vuser_id, char ** sgroup, int *scid);
char *	  lr_get_host_name (void);
char *	  lr_get_master_host_name (void);

 
long     lr_get_attrib_long	(char * attr_name);
char *   lr_get_attrib_string	(char * attr_name);
double   lr_get_attrib_double      (char * attr_name);

char * lr_paramarr_idx(const char * paramArrayName, unsigned int index);
char * lr_paramarr_random(const char * paramArrayName);
int    lr_paramarr_len(const char * paramArrayName);

int	lr_param_unique(const char * paramName);
int lr_param_sprintf(const char * paramName, const char * format, ...);


 
 
static void *ci_this_context = 0;






 








void lr_continue_on_error (int lr_continue);
char *   lr_decrypt (const char *EncodedString);


 
 
 
 
 
 



 







 















void   lr_abort (void);
void lr_exit(int exit_option, int exit_status);
void lr_abort_ex (unsigned long flags);

void   lr_peek_events (void);


 
 
 
 
 


void   lr_think_time (double secs);

 


void lr_force_think_time (double secs);


 
 
 
 
 



















int   lr_msg (char * fmt, ...);
int   lr_debug_message (unsigned int msg_class,
									    char * format,
										...);
# 505 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
void   lr_new_prefix (int type,
                                 char * filename,
                                 int line);
# 508 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
int   lr_log_message (char * fmt, ...);
int   lr_message (char * fmt, ...);
int   lr_error_message (char * fmt, ...);
int   lr_output_message (char * fmt, ...);
int   lr_vuser_status_message (char * fmt, ...);
int   lr_error_message_without_fileline (char * fmt, ...);
int   lr_fail_trans_with_error (char * fmt, ...);

 
 
 
 
 
# 531 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"

 
 
 
 
 





int   lr_next_row ( char * table);
int lr_advance_param ( char * param);



														  
														  

														  
														  

													      
 


char *   lr_eval_string (char * str);
int   lr_eval_string_ext (const char *in_str,
                                     unsigned long const in_len,
                                     char ** const out_str,
                                     unsigned long * const out_len,
                                     unsigned long const options,
                                     const char *file,
								     long const line);
# 565 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
void   lr_eval_string_ext_free (char * * pstr);

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int lr_param_increment (char * dst_name,
                              char * src_name);
# 588 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"













											  
											  

											  
											  
											  

int	  lr_save_var (char *              param_val,
							  unsigned long const param_val_len,
							  unsigned long const options,
							  char *			  param_name);
# 612 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
int   lr_save_string (const char * param_val, const char * param_name);
int   lr_free_parameter (const char * param_name);
int   lr_save_int (const int param_val, const char * param_name);
int   lr_save_timestamp (const char * tmstampParam, ...);
int   lr_save_param_regexp (const char *bufferToScan, unsigned int bufSize, ...);

int   lr_convert_double_to_integer (const char *source_param_name, const char * target_param_name);
int   lr_convert_double_to_double (const char *source_param_name, const char *format_string, const char * target_param_name);

 
 
 
 
 
 
# 683 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
void   lr_save_datetime (const char *format, int offset, const char *name);









 











 
 
 
 
 






 



char * lr_error_context_get_entry (char * key);

 



long   lr_error_context_get_error_id (void);


 
 
 

int lr_table_get_rows_num (char * param_name);

int lr_table_get_cols_num (char * param_name);

char * lr_table_get_cell_by_col_index (char * param_name, int row, int col);

char * lr_table_get_cell_by_col_name (char * param_name, int row, const char* col_name);

int lr_table_get_column_name_by_index (char * param_name, int col, 
											char * * const col_name,
											int * col_name_len);
# 744 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"

int lr_table_get_column_name_by_index_free (char * col_name);

 
 
 
 
# 759 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
int   lr_zip (const char* param1, const char* param2);
int   lr_unzip (const char* param1, const char* param2);

 
 
 
 
 
 
 
 

 
 
 
 
 
 
int   lr_param_substit (char * file,
                                   int const line,
                                   char * in_str,
                                   int const in_len,
                                   char * * const out_str,
                                   int * const out_len);
# 783 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
void   lr_param_substit_free (char * * pstr);


 
# 795 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"





char *   lrfnc_eval_string (char * str,
                                      char * file_name,
                                      long const line_num);
# 803 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"


int   lrfnc_save_string ( const char * param_val,
                                     const char * param_name,
                                     const char * file_name,
                                     long const line_num);
# 809 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"

int   lrfnc_free_parameter (const char * param_name );







typedef struct _lr_timestamp_param
{
	int iDigits;
}lr_timestamp_param;

extern const lr_timestamp_param default_timestamp_param;

int   lrfnc_save_timestamp (const char * param_name, const lr_timestamp_param* time_param);

int lr_save_searched_string(char *buffer, long buf_size, unsigned int occurrence,
			    char *search_string, int offset, unsigned int param_val_len, 
			    char *param_name);

 
char *   lr_string (char * str);

 
# 905 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"

int   lr_save_value (char * param_val,
                                unsigned long const param_val_len,
                                unsigned long const options,
                                char * param_name,
                                char * file_name,
                                long const line_num);
# 912 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"


 
 
 
 
 











int   lr_printf (char * fmt, ...);
 
int   lr_set_debug_message (unsigned int msg_class,
                                       unsigned int swtch);
# 934 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
unsigned int   lr_get_debug_message (void);


 
 
 
 
 

void   lr_double_think_time ( double secs);
void   lr_usleep (long);


 
 
 
 
 
 




int *   lr_localtime (long offset);


int   lr_send_port (long port);


# 1010 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"



struct _lr_declare_identifier{
	char signature[24];
	char value[128];
};

int   lr_pt_abort (void);

void vuser_declaration (void);






# 1039 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"


# 1051 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/lrun.h"
















 
 
 
 
 







int    _lr_declare_transaction   (char * transaction_name);


 
 
 
 
 







int   _lr_declare_rendezvous  (char * rendezvous_name);

 
 
 
 
 

 
int lr_enable_ip_spoofing();
int lr_disable_ip_spoofing();


 




int lr_convert_string_encoding(char *sourceString, char *fromEncoding, char *toEncoding, char *paramName);





 
 

















# 1 "c:\\users\\administrator\\desktop\\ali_webtours_full_script\\\\combined_ali_webtours_full_script.c" 2

# 1 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/SharedParameter.h" 1



 
 
 
 
# 100 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/SharedParameter.h"





typedef int PVCI2;
typedef int VTCERR2;

 
 
 

 
extern PVCI2    vtc_connect(char *servername, int portnum, int options);
extern VTCERR2  vtc_disconnect(int pvci);
extern VTCERR2  vtc_get_last_error(int pvci);

 
extern VTCERR2  vtc_query_column(int pvci, char *columnName, int columnIndex, char **outvalue);
extern VTCERR2  vtc_query_row(int pvci, int columnIndex, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_send_message(int pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_if_unique(int pvci, char *column, char *message, unsigned short *outRc);
extern VTCERR2  vtc_send_row1(int pvci, char *columnNames, char *messages, char *delimiter,  unsigned char sendflag, unsigned short *outUpdates);
extern VTCERR2  vtc_update_message(int pvci, char *column, int index , char *message, unsigned short *outRc);
extern VTCERR2  vtc_update_message_ifequals(int pvci, char	*columnName, int index,	char *message, char	*ifmessage,	unsigned short 	*outRc);
extern VTCERR2  vtc_update_row1(int pvci, char *columnNames, int index , char *messages, char *delimiter, unsigned short *outUpdates);
extern VTCERR2  vtc_retrieve_message(int pvci, char *column, char **outvalue);
extern VTCERR2  vtc_retrieve_messages1(int pvci, char *columnNames, char *delimiter, char ***outvalues);
extern VTCERR2  vtc_retrieve_row(int pvci, char ***outcolumns, char ***outvalues);
extern VTCERR2  vtc_increment(int pvci, char *column, int index , int incrValue, int *outValue);
extern VTCERR2  vtc_clear_message(int pvci, char *column, int index , unsigned short *outRc);
extern VTCERR2  vtc_clear_column(int pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_clear_row(int pvci, int rowIndex, unsigned short *outRc);

extern VTCERR2  vtc_create_column(int pvci, char *column,unsigned short *outRc);
extern VTCERR2  vtc_column_size(int pvci, char *column, int *size);
extern VTCERR2  vtc_ensure_index(int pvci, char *column, unsigned short *outRc);
extern VTCERR2  vtc_drop_index(int pvci, char *column, unsigned short *outRc);

extern VTCERR2  vtc_noop(int pvci);

 
extern void vtc_free(char *msg);
extern void vtc_free_list(char **msglist);

 


 




 




















 




 
 
 

extern VTCERR2  lrvtc_connect(char *servername, int portnum, int options);
extern VTCERR2  lrvtc_disconnect();
extern VTCERR2  lrvtc_query_column(char *columnName, int columnIndex);
extern VTCERR2  lrvtc_query_row(int columnIndex);
extern VTCERR2  lrvtc_send_message(char *columnName, char *message);
extern VTCERR2  lrvtc_send_if_unique(char *columnName, char *message);
extern VTCERR2  lrvtc_send_row1(char *columnNames, char *messages, char *delimiter,  unsigned char sendflag);
extern VTCERR2  lrvtc_update_message(char *columnName, int index , char *message);
extern VTCERR2  lrvtc_update_message_ifequals(char *columnName, int index, char 	*message, char *ifmessage);
extern VTCERR2  lrvtc_update_row1(char *columnNames, int index , char *messages, char *delimiter);
extern VTCERR2  lrvtc_retrieve_message(char *columnName);
extern VTCERR2  lrvtc_retrieve_messages1(char *columnNames, char *delimiter);
extern VTCERR2  lrvtc_retrieve_row();
extern int     lrvtc_increment(char *columnName, int index , int incrValue);
extern VTCERR2  lrvtc_clear_message(char *columnName, int index);
extern VTCERR2  lrvtc_clear_column(char *columnName);
extern VTCERR2  lrvtc_clear_row(int rowIndex);
extern VTCERR2  lrvtc_create_column(char *columnName);
extern int     lrvtc_column_size(char *columnName);
extern VTCERR2  lrvtc_ensure_index(char *columnName);
extern VTCERR2  lrvtc_drop_index(char *columnName);

extern VTCERR2  lrvtc_noop();

 
 
 

                               


 
 
 





















# 2 "c:\\users\\administrator\\desktop\\ali_webtours_full_script\\\\combined_ali_webtours_full_script.c" 2

# 1 "globals.h" 1



 
 

# 1 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/web_api.h" 1







# 1 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/as_web.h" 1























































 




 








 
 
 

  int
	web_add_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_add_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
	
  int
	web_add_auto_header(
		const char *		mpszHeader,
		const char *		mpszValue);

  int
	web_add_header(
		const char *		mpszHeader,
		const char *		mpszValue);
  int
	web_add_cookie(
		const char *		mpszCookie);
  int
	web_cleanup_auto_headers(void);
  int
	web_cleanup_cookies(void);
  int
	web_concurrent_end(
		const char * const	mpszReserved,
										 
		...								 
	);
  int
	web_concurrent_start(
		const char * const	mpszConcurrentGroupName,
										 
										 
		...								 
										 
	);
  int
	web_create_html_param(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim);
  int
	web_create_html_param_ex(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim,
		const char *		mpszNum);
  int
	web_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_disable_keep_alive(void);
  int
	web_enable_keep_alive(void);
  int
	web_find(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_get_int_property(
		const int			miHttpInfoType);
  int
	web_image(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_image_check(
		const char *		mpszName,
		...);
  int
	web_java_check(
		const char *		mpszName,
		...);
  int
	web_link(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

	
  int
	web_global_verification(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
  int
	web_reg_find(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
				
  int
	web_reg_save_param(
		const char *		mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 

  int
	web_convert_param(
		const char * 		mpszParamName, 
										 
		...);							 
										 
										 


										 

										 
  int
	web_remove_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
				
  int
	web_remove_auto_header(
		const char *		mpszHeaderName,
		...);							 
										 



  int
	web_remove_cookie(
		const char *		mpszCookie);

  int
	web_save_header(
		const char *		mpszType,	 
		const char *		mpszName);	 
  int
	web_set_certificate(
		const char *		mpszIndex);
  int
	web_set_certificate_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_set_connections_limit(
		const char *		mpszLimit);
  int
	web_set_max_html_param_len(
		const char *		mpszLen);
  int
	web_set_max_retries(
		const char *		mpszMaxRetries);
  int
	web_set_proxy(
		const char *		mpszProxyHost);
  int
	web_set_pac(
		const char *		mpszPacUrl);
  int
	web_set_proxy_bypass(
		const char *		mpszBypass);
  int
	web_set_secure_proxy(
		const char *		mpszProxyHost);
  int
	web_set_sockets_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue
	);
  int
	web_set_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue,
		...								 
	);
  int
	web_set_timeout(
		const char *		mpszWhat,
		const char *		mpszTimeout);
  int
	web_set_user(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);

  int
	web_sjis_to_euc_param(
		const char *		mpszParamName,
										 
		const char *		mpszParamValSjis);
										 

  int
	web_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_submit_form(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_set_proxy_bypass_local(
		const char * mpszNoLocal
		);

  int 
	web_cache_cleanup(void);

  int
	web_create_html_query(
		const char* mpszStartQuery,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_create_radio_button_param(
		const char *NameFiled,
		const char *NameAndVal,
		const char *ParamName
		);

  int
	web_convert_from_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										
  int
	web_convert_to_formatted(
		const char * mpszArg1,
		...);							 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_ex(
		const char * mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_xpath(
		const char * mpszParamName,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_reg_save_param_regexp(
		 const char * mpszParamName,
		 ...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_run(
		const char * mpszCode,
		...);							
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_js_reset(void);










# 631 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/as_web.h"


# 644 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/as_web.h"



























# 682 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/as_web.h"

 
 
 


  int
	FormSubmit(
		const char *		mpszFormName,
		...);
  int
	InitWebVuser(void);
  int
	SetUser(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);
  int
	TerminateWebVuser(void);
  int
	URL(
		const char *		mpszUrlName);
























# 750 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/as_web.h"



 
 
 






# 9 "C:\\Program Files (x86)\\HP\\LoadRunner\\include/web_api.h" 2

















 






 














  int
	web_reg_add_cookie(
		const char *		mpszCookie,
		...);							 
										 

  int
	web_report_data_point(
		const char *		mpszEventType,
		const char *		mpszEventName,
		const char *		mpszDataPointName,
		const char *		mpszLAST);	 
										 
										 
										 

  int
	web_text_link(
		const char *		mpszStepName,
		...);

  int
	web_element(
		const char *		mpszStepName,
		...);

  int
	web_image_link(
		const char *		mpszStepName,
		...);

  int
	web_static_image(
		const char *		mpszStepName,
		...);

  int
	web_image_submit(
		const char *		mpszStepName,
		...);

  int
	web_button(
		const char *		mpszStepName,
		...);

  int
	web_edit_field(
		const char *		mpszStepName,
		...);

  int
	web_radio_group(
		const char *		mpszStepName,
		...);

  int
	web_check_box(
		const char *		mpszStepName,
		...);

  int
	web_list(
		const char *		mpszStepName,
		...);

  int
	web_text_area(
		const char *		mpszStepName,
		...);

  int
	web_map_area(
		const char *		mpszStepName,
		...);

  int
	web_eval_java_script(
		const char *		mpszStepName,
		...);

  int
	web_reg_dialog(
		const char *		mpszArg1,
		...);

  int
	web_reg_cross_step_download(
		const char *		mpszArg1,
		...);

  int
	web_browser(
		const char *		mpszStepName,
		...);

  int
	web_control(
		const char *		mpszStepName,
		...);

  int
	web_set_rts_key(
		const char *		mpszArg1,
		...);

  int
	web_save_param_length(
		const char * 		mpszParamName,
		...);

  int
	web_save_timestamp_param(
		const char * 		mpszParamName,
		...);

  int
	web_load_cache(
		const char *		mpszStepName,
		...);							 
										 

  int
	web_dump_cache(
		const char *		mpszStepName,
		...);							 
										 
										 

  int
	web_reg_find_in_log(
		const char *		mpszArg1,
		...);							 
										 
										 

  int
	web_get_sockets_info(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 

  int
	web_add_cookie_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

  int
	web_hook_java_script(
		const char *		mpszArg1,
		...);							 
										 
										 
										 

 
 
 
 
 
 
 
 
 
 
 
  int
	web_reg_async_attributes(
		const char *		mpszArg,
		...
	);

 
 
 
 
 
 
  int
	web_sync(
		 const char *		mpszArg1,
		 ...
	);

 
 
 
 
  int
	web_stop_async(
		const char *		mpszArg1,
		...
	);

 
 
 
 
 

 
 
 

typedef enum WEB_ASYNC_CB_RC_ENUM_T
{
	WEB_ASYNC_CB_RC_OK,				 

	WEB_ASYNC_CB_RC_ABORT_ASYNC_NOT_ERROR,
	WEB_ASYNC_CB_RC_ABORT_ASYNC_ERROR,
										 
										 
										 
										 
	WEB_ASYNC_CB_RC_ENUM_COUNT
} WEB_ASYNC_CB_RC_ENUM;

 
 
 

typedef enum WEB_CONVERS_CB_CALL_REASON_ENUM_T
{
	WEB_CONVERS_CB_CALL_REASON_BUFFER_RECEIVED,
	WEB_CONVERS_CB_CALL_REASON_END_OF_TASK,

	WEB_CONVERS_CB_CALL_REASON_ENUM_COUNT
} WEB_CONVERS_CB_CALL_REASON_ENUM;

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

typedef
int														 
	(*RequestCB_t)();

typedef
int														 
	(*ResponseBodyBufferCB_t)(
		  const char *		aLastBufferStr,
		  int				aLastBufferLen,
		  const char *		aAccumulatedStr,
		  int				aAccumulatedLen,
		  int				aHttpStatusCode);

typedef
int														 
	(*ResponseCB_t)(
		  const char *		aResponseHeadersStr,
		  int				aResponseHeadersLen,
		  const char *		aResponseBodyStr,
		  int				aResponseBodyLen,
		  int				aHttpStatusCode);

 
 
 

typedef enum WEB_CONVERS_UTIL_RC_ENUM_T
{
	WEB_CONVERS_UTIL_RC_OK,
	WEB_CONVERS_UTIL_RC_CONVERS_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_TASK_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_NOT_FOUND,
	WEB_CONVERS_UTIL_RC_INFO_UNAVIALABLE,
	WEB_CONVERS_UTIL_RC_INVALID_ARGUMENT,

	WEB_CONVERS_UTIL_RC_ENUM_COUNT
} WEB_CONVERS_UTIL_RC_ENUM;

 
 
 

  int					 
	web_util_set_request_url(
		  const char *		aUrlStr);

  int					 
	web_util_set_request_body(
		  const char *		aRequestBodyStr);

  int					 
	web_util_set_formatted_request_body(
		  const char *		aRequestBodyStr);


 
 
 
 
 





# 7 "globals.h" 2

# 1 "lrw_custom_body.h" 1
 




# 8 "globals.h" 2


 
 

Extended_Log_On()
{
lr_set_debug_message (16 | 8, 1);
return 0;
}
Extended_Log_Off()
{
lr_set_debug_message (16 | 8, 0);
return 0;
}


# 3 "c:\\users\\administrator\\desktop\\ali_webtours_full_script\\\\combined_ali_webtours_full_script.c" 2

# 1 "vuser_init.c" 1
 







vuser_init()
{
	 
	
	
	 

	return 0;
}
# 4 "c:\\users\\administrator\\desktop\\ali_webtours_full_script\\\\combined_ali_webtours_full_script.c" 2

# 1 "Action.c" 1
Action()
{
	 
	
	int a,b,c,i,d,newint,q,w,e,r,t,y,u;
	char *temp,*temp1,*token,*temp2;
	long testfile;
	char *file="D:\\Fileoperations\\correlationstrings.txt";
	char *ip;
	char *ip1;
	
	 
	lr_get_host_name(); 
	 
	lr_get_master_host_name();
	
	 

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

	 
	web_set_max_html_param_len("9999");
	
	 
	
	lr_start_transaction("webtours_ticketbooking_01_welcomepage"); 
	
	 
	
	web_reg_find("Text=Web Tours","savecount=s1",
		"LAST");
	
	 
	 
	 
	 
	
 
 
 
 
 
 
	                   
	lr_get_vuser_ip();
	
	 
	
 
 
 
 
 
	
	 
	 
	web_reg_save_param("sessionid",
	                   "LB/IC=name=userSession value=",
	                   "RB/IC=>",
	                   "ORD=all",
	                   "LAST");
		
	
	 

	web_url("webtours", 
		"URL=http://127.0.0.1:1080/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		"LAST");
	
	 
	
 
 
 
 
 
	
	 
	
	 
# 110 "Action.c"
	q=web_get_int_property(1);
	lr_output_message("%d",q);
	
	if(q==200)
	{
		
		lr_output_message("welcome page is passed");
		lr_end_transaction("webtours_ticketbooking_01_welcomepage", 0);
	}
	else
	{
		lr_error_message("welcome page is failed");
		lr_end_transaction("webtours_ticketbooking_01_welcomepage", 1);
		lr_exit(5,1);
	}
	 

	 
	lr_think_time(10);
	lr_start_transaction("webtours_ticketbooking_02_login");
	
	
	 
	 

	web_reg_find("Text=Web Tours","savecount=s2","LAST");
	
	 
	 
	
	Extended_Log_On();

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"ITEMDATA", 
		"Name=userSession", "Value={sessionid}", "ENDITEM", 
		"Name=username", "Value={username}", "ENDITEM", 	 
		"Name=password", "Value=bean", "ENDITEM", 
		"Name=login.x", "Value=45", "ENDITEM", 
		"Name=login.y", "Value=5", "ENDITEM", 
		"Name=JSFormSubmit", "Value=off", "ENDITEM", 
		"LAST");
	Extended_Log_On();
	
	 
	
	web_save_timestamp_param("timestamp","LAST");
	lr_output_message("timestamp is %d",lr_eval_string("{timestamp}"));
	
	 
	
	lr_save_datetime("%c",0,"Date");
	lr_output_message(lr_eval_string("{Date}"));
	
	lr_save_datetime("%c",0 +86400,"OneDayAdvanceDate");
	lr_output_message(lr_eval_string("{OneDayAdvanceDate}"));
	
	lr_save_datetime("%c",0,"TimeNow");
	lr_output_message(lr_eval_string("{TimeNow}"));
	
	lr_save_datetime("%c",0 +3600,"TimeNowPlusOneHour");
	lr_output_message(lr_eval_string("{TimeNowPlusOneHour}"));
	
	 
	                  
	w=web_get_int_property(1);
	lr_output_message("%d",w);
	
	if(w==200)
	{
		
		lr_output_message("welcome page is passed");
		lr_end_transaction("webtours_ticketbooking_02_login", 0);
	}
	else
	{
		lr_error_message("welcome page is failed");
		lr_end_transaction("webtours_ticketbooking_02_login", 1);
		lr_exit(5,1);
	}
		lr_think_time(10);
 
	lr_start_transaction("webtours_ticketbooking_03_flights");

	web_reg_find("Text=Web Tours","savecount=s3",
		"LAST");
	
	 
	 
	
	web_reg_save_param("cities","lb=<option value=\"","rb=\">","ord=all","LAST");
	web_reg_save_param("denvercity","lb=<option selected=\"selected\" value=\"","rb=\">","ord=all","LAST");
	
	web_url("welcome.pl", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		"LAST");
	
	 
	
	d=rand()%9+1;
	temp=lr_paramarr_idx("cities",d);
	lr_save_string(temp,"newdepcity");
	
random:
	
	d=rand()%9+10;
	temp1=lr_paramarr_idx("cities",d);
	lr_save_string(temp1,"newarrcity");

	 
	
	if(strcmp(temp,temp1)==0)
		
		goto random;
	
	 
	
	temp2=lr_paramarr_idx("cities",6);
	token=(char *)strtok(temp2,"c");
	lr_save_string(token,"newstring");
	
	 
	
	
	a=lr_paramarr_len("denvercity");
	b=lr_paramarr_len("cities");
	
	for(i=1;i<=a;i++)
	{
		c=b+i;
		lr_save_int(c,"newint");
		temp=lr_paramarr_idx("denvercity",i);
		lr_save_string(temp,lr_eval_string("cities_{newint}"));
	}
	
	 
# 268 "Action.c"
	
	e=web_get_int_property(1);
	lr_output_message("%d",e);
	if(e==200)
	{
		lr_output_message("page 3 pass");
		lr_end_transaction("webtours_ticketbooking_03_flights",0);	
	}
	else
	{
		lr_error_message("page 3 fail");
		lr_end_transaction("webtours_ticketbooking_03_flights",1);
		lr_exit(5,1);
	}
 
		lr_think_time(10);

	lr_start_transaction("webtours_ticketbooking_04_findflight");

	web_reg_find("Text=Flight Selections","savecount=s4", 
		"LAST");

	web_submit_data("reservations.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		"ITEMDATA", 
		"Name=advanceDiscount", "Value=0", "ENDITEM", 
		"Name=depart", "Value={newdepcity}", "ENDITEM", 
		"Name=departDate", "Value={departdate}", "ENDITEM", 	 
		"Name=arrive", "Value={newarrcity}", "ENDITEM", 
		"Name=returnDate", "Value={arrivedate}", "ENDITEM", 
		"Name=numPassengers", "Value=1", "ENDITEM", 
		"Name=seatPref", "Value=Aisle", "ENDITEM", 
		"Name=seatType", "Value=Coach", "ENDITEM", 
		"Name=findFlights.x", "Value=26", "ENDITEM", 
		"Name=findFlights.y", "Value=11", "ENDITEM", 
		"Name=.cgifields", "Value=roundtrip", "ENDITEM", 
		"Name=.cgifields", "Value=seatType", "ENDITEM", 
		"Name=.cgifields", "Value=seatPref", "ENDITEM", 
		"LAST");
	r=web_get_int_property(1);
		lr_output_message("%d",r);
	if(r==200)
	{
		lr_output_message("page 4 pass");
		lr_end_transaction("webtours_ticketbooking_04_findflight",0);
	}
	else{
		lr_error_message("page 4 fail");
		lr_end_transaction("webtours_ticketbooking_04_findflight",1);
		lr_exit(5,1);
	}
	 
# 336 "Action.c"
 
lr_think_time(10);
	lr_start_transaction("webtours_ticketbooking_05_selectflight");

	web_reg_find("Text=Flight Reservation", "savecount=s5",
		"LAST");
	

	web_submit_data("reservations.pl_2", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		"ITEMDATA", 
		"Name=outboundFlight", "Value=182;1153;05/07/2015", "ENDITEM", 
		"Name=numPassengers", "Value=1", "ENDITEM", 
		"Name=advanceDiscount", "Value=0", "ENDITEM", 
		"Name=seatType", "Value=Coach", "ENDITEM", 
		"Name=seatPref", "Value=Aisle", "ENDITEM", 
		"Name=reserveFlights.x", "Value=21", "ENDITEM", 
		"Name=reserveFlights.y", "Value=10", "ENDITEM", 
		"LAST");
	t=web_get_int_property(1);
	lr_output_message("%d",t);
	if(t==200)
	{
		lr_output_message("page  5  pass");
		lr_end_transaction("webtours_ticketbooking_05_selectflight",0);	
			}
	else
	{
		lr_error_message("page 5 fail");
		lr_end_transaction("webtours_ticketbooking_05_selectflight",1);	
		lr_exit(5,1);
	}
	
	 
# 386 "Action.c"
	 
lr_think_time(10);
	lr_start_transaction("webtours_ticketbooking_06_payment");

	web_reg_find("Text=Reservation Made!", "savecount=s6",
		"LAST");

	

	web_submit_data("reservations.pl_3", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		"ITEMDATA", 
		"Name=firstName", "Value=Jojo", "ENDITEM", 
		"Name=lastName", "Value=Bean", "ENDITEM", 
		"Name=address1", "Value=", "ENDITEM", 
		"Name=address2", "Value=", "ENDITEM", 
		"Name=pass1", "Value=Jojo Bean", "ENDITEM", 
		"Name=creditCard", "Value=34774545847689459645", "ENDITEM", 
		"Name=expDate", "Value=", "ENDITEM", 
		"Name=saveCC", "Value=on", "ENDITEM", 
		"Name=oldCCOption", "Value=on", "ENDITEM", 
		"Name=numPassengers", "Value=1", "ENDITEM", 
		"Name=seatType", "Value=Coach", "ENDITEM", 
		"Name=seatPref", "Value=Aisle", "ENDITEM", 
		"Name=outboundFlight", "Value=182;1153;05/07/2015", "ENDITEM", 
		"Name=advanceDiscount", "Value=0", "ENDITEM", 
		"Name=returnFlight", "Value=", "ENDITEM", 
		"Name=JSFormSubmit", "Value=off", "ENDITEM", 
		"Name=buyFlights.x", "Value=40", "ENDITEM", 
		"Name=buyFlights.y", "Value=13", "ENDITEM", 
		"Name=.cgifields", "Value=saveCC", "ENDITEM", 
		"LAST");
	y=web_get_int_property(1);
	lr_output_message("%d",y);
	if(y==200)
	{
		lr_output_message("page 6 pass");
		
		lr_end_transaction("webtours_ticketbooking_06_payment",0);	
		
	}
	else
	{
		lr_error_message("page  6 fail");
		lr_end_transaction("webtours_ticketbooking_06_payment",1);	
		lr_exit(5,1);
	}
	 
# 451 "Action.c"
	
	return 0;
}
# 5 "c:\\users\\administrator\\desktop\\ali_webtours_full_script\\\\combined_ali_webtours_full_script.c" 2

# 1 "Fileoperations_write.c" 1
Fileoperations_write()
{
	
	long fp;
	
            fp= fopen("D:\\Fileoperations\\correlationstrings1.txt","a");
            lr_save_datetime("%d-%m-%y",0 ,"datetime");
            fprintf(fp,"Iteration Number is %s \n",lr_eval_string("{prmIterationNumber}"));
            fprintf(fp,"Todays date is %s \n",lr_eval_string("{datetime}"));
            lr_save_datetime("%d-%m-%y",0 + 86400 ,"datetime1");
            fprintf(fp,"date after one day  is %s \n",lr_eval_string("{datetime1}"));
            fclose(fp);
            
            
            
	return 0;
}
# 6 "c:\\users\\administrator\\desktop\\ali_webtours_full_script\\\\combined_ali_webtours_full_script.c" 2

# 1 "Fileoperations_read.c" 1
Fileoperations_read()
{
	 
# 23 "Fileoperations_read.c"
 
 

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

	lr_debug_message(1, "gggg");

	


}
# 7 "c:\\users\\administrator\\desktop\\ali_webtours_full_script\\\\combined_ali_webtours_full_script.c" 2

# 1 "Fileoperations.c" 1
Fileoperations()
{
	 
# 58 "Fileoperations.c"

                                 

                                         

                                 








	
	return 0;
}
# 8 "c:\\users\\administrator\\desktop\\ali_webtours_full_script\\\\combined_ali_webtours_full_script.c" 2

# 1 "vuser_end.c" 1
vuser_end()
{

	lr_think_time(10);
	lr_start_transaction("webtours_ticketbooking_07_logout");
	Extended_Log_On();

	web_reg_find("Text=Web Tours","savecount=s7", 
		"LAST");


	web_url("welcome.pl_2", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"LAST");
	if(atoi(lr_eval_string("{s7}"))>0)
	{
		lr_output_message("page7 pass");
	lr_end_transaction("webtours_ticketbooking_07_logout",0);	
	}
else
{
	lr_error_message("page7 fail");
	lr_end_transaction("webtours_ticketbooking_07_logout",1);
	lr_exit(5,1);
}
	
Extended_Log_On();
	return 0;
}
# 9 "c:\\users\\administrator\\desktop\\ali_webtours_full_script\\\\combined_ali_webtours_full_script.c" 2

