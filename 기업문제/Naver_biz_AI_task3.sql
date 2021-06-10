SELECT c.country as country, sum(IFNULL(t.export, 0)) as export, sum(IFNULL(t.import, 0)) as import
FROM
companies as c
LEFT OUTER JOIN
(SELECT t.company, sum(t.export) as export, sum(t.import) as import
FROM
(SELECT t.seller as company, sum(t.value) as export, 0 as import
FROM trades t
GROUP BY t.seller
UNION
SELECT t.buyer as company, 0 as export, sum(t.value) as import
FROM trades t
GROUP BY t.buyer) as t
GROUP BY t.company) as t
ON c.name = t.company
GROUP BY c.country
ORDER BY c.country ASC