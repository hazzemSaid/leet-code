# Write your MySQL query statement below
select employee_id ,department_id
from Employee e
where primary_flag = "Y" || (select count(*)
from Employee s where e.employee_id = s.employee_id )=1 ;