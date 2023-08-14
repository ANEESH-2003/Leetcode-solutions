# Write your MySQL query statement below
select  a.machine_id , round(avg(b.timestamp-a.timestamp),3) as processing_time
from activity as a left join activity as b
on a.activity_type='start' and b.activity_type='end' and a.process_id=b.process_id
and a.machine_id=b.machine_id
group by machine_id