-- select name as Customers
-- from Customers c
-- where not exists(
--     select 1
--     from orders o
--     where o.customerId = c.id
-- );

select c.name as Customers
from Customers c
left join Orders o
on c.id = o.customerId
where o.customerId is NULL;