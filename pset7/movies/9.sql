select distinct name from movies a
inner join stars b on b.movie_id = a.id
inner join people c on c.id = b.person_id
where a.year = 2004
order by c.birth;