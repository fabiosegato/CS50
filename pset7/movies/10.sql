select distinct name from movies a
inner join directors b on b.movie_id = a.id
inner join people c on c.id = b.person_id
inner join ratings d on d.movie_id = a.id
where d.rating >= 9;