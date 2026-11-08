# Arena Allocator

With arena allocation there are in general 3 live times

1. Program lifetime
2. Job lifetime
3. Task lifetime

Program life time is self explanitory, what data needs to survive for the entire program.  
Job lifetime is that we have an arena that like the program one, lives for the duration of an entire job.
Task Lifetime is essentially temporary storage, the idea that we have a task inside of a job. Then we can have scratch arenas or snapshots that are reset everytime we get in there.

## Stratch arena
a stracth arena is just a arena where you say "strach that". Its where we reset it rather than release it. That way we dont need to allocate again.

This can be achived with not deallocating arenas, and maybe using a snapshot for creating temporary regions in an arena. 

In principle you can have an assortment of arenas preallocated for a job. Then a job takes one, marks it as taken, and then uses it. Once its done it simply resets the region and returns it.
