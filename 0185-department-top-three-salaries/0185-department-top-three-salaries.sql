# Write your MySQL query statement below
with cte as
(select e.id,e.name as Employee,e.salary as Salary,d.name as department,
dense_rank() over(partition by d.id order by e.salary desc) as rnk
from employee e join department d
on e.departmentid=d.id)
select department,employee,salary from cte where rnk<=3;