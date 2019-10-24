// Copyright (c) 2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_INDIRECTMAP_H
#define BITCOIN_INDIRECTMAP_H
#include<unordered_map>

template <class T>
struct DereferencingComparator { bool operator()(const T a, const T b) const { return *a < *b; } };

template <class H, class K>
struct DereferencingHasher {
    private:
        const H s{};
    public:
    size_t operator()(const K& key) const {
        return s(*key);
    }
};

/* Map whose keys are pointers, but are compared by their dereferenced values.
 *
 * Differs from a plain std::map<const K*, T, DereferencingComparator<K*> > in
 * that methods that take a key for comparison take a K rather than taking a K*
 * (taking a K* would be confusing, since it's the value rather than the address
 * of the object for comparison that matters due to the dereferencing comparator).
 *
 * Objects pointed to by keys must not be modified in any way that changes the
 * result of DereferencingComparator.
 */
template <class K, class T, class H>
class indirectmap {
private:
    typedef std::unordered_map<const K*, T, DereferencingHasher<H, const K*>, DereferencingComparator<const K*> > base;
    base m;
public:
    typedef typename base::iterator iterator;
    typedef typename base::const_iterator const_iterator;
    typedef typename base::size_type size_type;
    typedef typename base::value_type value_type;

    // passthrough (pointer interface)
    std::pair<iterator, bool> insert(const value_type& value) { return m.insert(value); }
    template< class... Args >
        std::pair<iterator,bool> emplace( Args&&... args )
     { return m.emplace(std::forward<Args>(args)...);}

    // pass address (value interface)
    iterator find(const K& key)                     { return m.find(&key); }
    const_iterator find(const K& key) const         { return m.find(&key); }
    iterator lower_bound(const K& key)              { return m.lower_bound(&key); }
    const_iterator lower_bound(const K& key) const  { return m.lower_bound(&key); }
    size_type erase(const K& key)                   { return m.erase(&key); }
    size_type count(const K& key) const             { return m.count(&key); }

    // Explicit address required -- otherwise, may accidentall insert temporary
    T& operator[]( const K* key ) {return m[key];}

    // passthrough
    iterator erase(const_iterator pos)                   { return m.erase(pos); }
    bool empty() const              { return m.empty(); }
    size_type size() const          { return m.size(); }
    size_type max_size() const      { return m.max_size(); }
    void clear()                    { m.clear(); }
    iterator begin()                { return m.begin(); }
    iterator end()                  { return m.end(); }
    const_iterator begin() const    { return m.begin(); }
    const_iterator end() const      { return m.end(); }
    const_iterator cbegin() const   { return m.cbegin(); }
    const_iterator cend() const     { return m.cend(); }
};

#endif // BITCOIN_INDIRECTMAP_H
