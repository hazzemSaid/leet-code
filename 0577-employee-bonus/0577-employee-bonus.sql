SELECT e.name, s.bonus
FROM Employee e
LEFT JOIN Bonus s
    ON s.empId = e.empId
WHERE s.bonus < 1000 OR s.empId IS NULL;
