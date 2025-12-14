# Write your MySQL query statement below
SELECT 
    A.machine_id ,round(sum( B.timestamp - A.timestamp )/count(A.machine_id),3) AS processing_time 
FROM 
    Activity A
LEFT JOIN 
    Activity B
ON 
    (A.machine_id  = B.machine_id AND A.process_id = B.process_id AND A.activity_type !=B.activity_type  )
WHERE
    A.activity_type  != 'end'
GROUP BY 
    A.machine_id;
