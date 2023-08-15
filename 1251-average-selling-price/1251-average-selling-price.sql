# Write your MySQL query statement below
select a.product_id,round(sum(a.price*b.units*1.00)/sum(b.units*1.00),2) as average_price
from prices as a right join
unitssold as b 
on a.product_id=b.product_id and b.purchase_date<=a.end_date and b.purchase_date>=a.start_date
group by a.product_id