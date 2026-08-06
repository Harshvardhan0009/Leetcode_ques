select e.name, b.bonus from
employee as e
left join Bonus as b on
e.empid = b.empid
where b.bonus<1000 or b.bonus is NULL;