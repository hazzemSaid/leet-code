SELECT 
    firstName  , lastName   ,  city  , state   
FROM
    Person  p 
LEFT join
    Address a  
ON
    a.personId    =  p.personId       