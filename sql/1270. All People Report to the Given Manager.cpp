select a.employee_id
from Employees a
left join Employees b on a.manager_id = b.employee_id
left join Employees c on b.manager_id = c.employee_id
left join Employees d on c.manager_id = d.employee_id
where d.employee_id = 1 and a.employee_id <> 1
