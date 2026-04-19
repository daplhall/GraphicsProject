# What features should we have
The abillity to dynamically allocate memory
 - This should be a toggle in the arena
    (Arena_create(capacity, arena.dynamic))
    (Arena_create(capacity, arena.static))

The abillity to lay managers untop of a segment of arena memory,  these are called partions.
 - AreanPartition
   * This could be dynamic, as it just requests from the top arena, which then allocates a new block for it, and then this block is part of the the partions linked list of memory
 - FixedPoolPartition
   * Same as arena partition in terms of dynmaic lifetime 
   * Creates fixed size pool that manages the underlying memory; This blocks returned are static arenas
  