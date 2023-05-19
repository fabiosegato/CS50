select title from (
select distinct title from movies a
inner join stars b on b.movie_id = a.id
inner join people c on c.id = b.person_id
inner join ratings d on d.movie_id = a.id
where c.name = 'Chadwick Boseman'
order by d.rating desc
) limit 5;