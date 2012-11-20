Drop view if exists warranty_inspection_report_view;
CREATE ALGORITHM=MERGE SQL SECURITY DEFINER VIEW `warranty_inspection_report_view` As
SELECT u.uid,im.*,wm.wcl_assign 
               FROM users u join warranty_user wu on (wu.uid = u.uid and wu.is_internal = 1)
               join warranty_user_division wud on wud.wuid = wu.id
               join wcl_mstr wm on wud.wdid = wm.wcl_division_id
               join inspection_master im on wm.wcl_domain = im.domain and wm.wcl_nbr = im.claim_nbr;
Drop view if exists warranty_repair_parts_view;
CREATE ALGORITHM=MERGE SQL SECURITY DEFINER VIEW `warranty_repair_parts_view` As
    select u.uid AS uid, wcl.*, wcli.*, if(wcli.wcli_root_cause = 1, 'Yes', 'No') as 'root_cause'
    from users u
    join warranty_user wu on wu.uid = u.uid
    join warranty_user_division wud on wud.wuid = wu.id
    join wcl_mstr wcl on (wu.is_internal = 1
      or  (wu.is_internal = 0 and (wcl.wcl_owner = u.uid or wcl.wcl_cust = wud.warranty_customer)))
      and wcl.wcl_division_id = wud.wdid
    join wcld_det wd on wd.wcld_wcl_id = wcl.wcl_id
    left join wcli_det wcli on wcli.wcli_wcld_id = wd.wcld_id
      where wcli.wcli_return_req = 1 and wcli.wcli_receipt_date is NULL;