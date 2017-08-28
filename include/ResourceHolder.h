#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <map>
#include <memory>
#include <string>
#include <cassert>
#include <iostream>

//#include <typeinfo>

template<typename Resource, typename ID>
class ResourceHolder
{
public:
    ResourceHolder(const ResourceHolder&) = delete;
    ResourceHolder& operator=(const ResourceHolder&) = delete;

    static ResourceHolder& instance();

    Resource& get(ID id);
    const Resource& get(ID id) const;

    template<typename... Args>
    void load(ID id, const std::string& fileName, Args&&... args);

private:
    ResourceHolder() { std::cout << __FUNCTION__ << " " << typeid(Resource).name() << std::endl; }
    void insertResource(std::unique_ptr<Resource> res, ID id);

private:
    std::map<ID, std::unique_ptr<Resource>> m_resources;
};

template<typename Resource, typename ID>
template<typename... Args>
void ResourceHolder<Resource, ID>::load(ID id, const std::string& fileName, Args&&... args)
{
    auto it = m_resources.find(id);
    //assert(it == std::end(m_resources));
    if (it != std::end(m_resources))
    {
        std::cout << "Resource with this ID is already loaded" << std::endl;
        return;
    }

    std::unique_ptr<Resource> newRes {new Resource()};
    if (!newRes->loadFromFile(fileName, std::forward<Args>(args)...))
    {
        std::cerr << "Error loading resource from " << fileName << std::endl;
        return;
    }
    insertResource(std::move(newRes), id);
}

template<typename Resource, typename ID>
Resource& ResourceHolder<Resource, ID>::get(ID id)
{
    auto it = m_resources.find(id);
    assert(it != std::end(m_resources));
    return *it->second;
}

template<typename Resource, typename ID>
const Resource& ResourceHolder<Resource, ID>::get(ID id) const
{
    auto it = m_resources.find(id);
    assert(it != std::end(m_resources));
    return *it->second;
}

template<typename Resource, typename ID>
void ResourceHolder<Resource, ID>::insertResource(std::unique_ptr<Resource> res, ID id)
{
    auto ins = m_resources.insert(std::make_pair(id, std::move(res)));
    assert(ins.second);
}

template<typename Resource, typename ID>
ResourceHolder<Resource, ID>& ResourceHolder<Resource, ID>::instance()
{
    static ResourceHolder inst;
    return inst;
}
#endif // RESOURCEMANAGER_H
