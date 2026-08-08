select p1.id
from weather p1
join weather p2
ON DATEDIFF(p1.recordDate, p2.recordDate) = 1
where p1.temperature>p2.temperature;
