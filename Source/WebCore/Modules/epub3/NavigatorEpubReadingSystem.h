#ifndef NavigatorEpubReadingSystem_h
#define NavigatorEpubReadingSystem_h

#if ENABLE(EPUB3)

#include "Supplementable.h"

namespace WebCore {

class Navigator;
class EpubReadingSystem;

class NavigatorEpubReadingSystem : public Supplement<Navigator> {
public:
    virtual ~NavigatorEpubReadingSystem();
    static NavigatorEpubReadingSystem* from(Navigator*);

    static EpubReadingSystem* epubReadingSystem(Navigator*);

private:
    NavigatorEpubReadingSystem();
    static const char* supplementName();

    EpubReadingSystem* webkitEpubReadingSystem(Navigator*);

    RefPtr<EpubReadingSystem> m_epubReadingSystem;
};

} // namespace WebCore

#endif // ENABLE(EPUB3)

#endif // NavigatorEpubReadingSystem_h
