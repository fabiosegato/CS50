select name from movies a
inner join stars b on b.movie_id = a.id
inner join people c on c.id = b.person_id
where a.title = 'Toy Story';