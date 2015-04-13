#ifndef EpubReadingSystem_h
#define EpubReadingSystem_h

#if ENABLE(EPUB3)

#include <wtf/HashSet.h>
#include <wtf/RefCounted.h>
#include <wtf/Vector.h>
#include <wtf/text/StringHash.h>
#include <wtf/text/WTFString.h>

namespace WebCore {

class EpubReadingSystem: public RefCounted<EpubReadingSystem> {
public:
    static PassRefPtr<EpubReadingSystem> create()
    {
        return adoptRef(new EpubReadingSystem);
    }
    ~EpubReadingSystem();

    const String& name() const { return m_name; }
    void name(const String& name) { m_name = name; }

    const String& version() const { return m_version; }
    void version(const String& version) { m_version = version; }

    const String& layoutStyle() const { return m_layoutStyle; }
    void layoutStyle(const String& layoutStyle) { m_layoutStyle = layoutStyle; }

    void setFeature(const String& feature);
    bool hasFeature(const String& feature, const String& version = "");
private:
    EpubReadingSystem();
    String m_name;
    String m_version;
    String m_layoutStyle;
    HashSet<String> m_features;
};

} // namespace WebCore

#endif // ENABLE(EPUB3)

#endif // EpubReadingSystem_h
