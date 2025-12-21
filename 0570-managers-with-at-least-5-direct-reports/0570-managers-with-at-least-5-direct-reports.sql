# Write your MySQL query statement below
select s.name
from Employee s
left join Employee a
on s.id = a.managerId
where a.id is not  null
group by s.id
having count(s.id)>=5
;
