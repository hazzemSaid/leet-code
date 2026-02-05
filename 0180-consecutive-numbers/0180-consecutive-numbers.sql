SELECT DISTINCT num AS ConsecutiveNums
FROM (
    SELECT 
        num, 
        LEAD(num, 1) OVER (ORDER BY id) as next_1,
        LEAD(num, 2) OVER (ORDER BY id) as next_2
    FROM Logs
) AS subquery
WHERE num = next_1 AND num = next_2;