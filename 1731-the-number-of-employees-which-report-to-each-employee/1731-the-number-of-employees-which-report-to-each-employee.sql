SELECT
    t.reports_to AS employee_id,
    e.name,
    t.reports_count,
    t.average_age
FROM (
    SELECT
        reports_to,
        COUNT(*) AS reports_count,
        ROUND(AVG(age), 0) AS average_age
    FROM Employees
    WHERE reports_to IS NOT NULL
    GROUP BY reports_to
) t
JOIN Employees e
    ON e.employee_id = t.reports_to
ORDER BY t.reports_to;
