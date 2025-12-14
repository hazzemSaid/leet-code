SELECT 
    t.student_id,
    t.student_name,
    t.subject_name,
    COUNT(e.subject_name) AS attended_exams 
FROM (
    SELECT s.student_id, s.student_name, sub.subject_name
    FROM Students s
    JOIN Subjects sub  -- this acts as CROSS JOIN
) t
LEFT JOIN Examinations e
    ON t.student_id = e.student_id
   AND t.subject_name = e.subject_name
GROUP BY t.student_id, t.student_name, t.subject_name
ORDER BY t.student_id, t.subject_name;
