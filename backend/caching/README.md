# Caching

cache_aside.py: the app checks the cache first, if missed, it reads the database then saves the result in the cache

ttl_and_eviction.py: every entry expires after a set time, so old data cannot live forever