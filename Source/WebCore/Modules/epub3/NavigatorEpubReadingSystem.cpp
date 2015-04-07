#include "config.h"
#include "NavigatorEpubReadingSystem.h"

#if ENABLE(EPUB3)

#include "EpubReadingSystem.h"
#include "Navigator.h"
#include <loader/FrameLoader.h>
#include <loader/FrameLoaderClient.h>
#include <page/Frame.h>
#include <wtf/PassOwnPtr.h>

namespace WebCore {

NavigatorEpubReadingSystem::NavigatorEpubReadingSystem()
{
}

NavigatorEpubReadingSystem::~NavigatorEpubReadingSystem()
{
}

const char* NavigatorEpubReadingSystem::supplementName()
{
    return "NavigatorEpubReadingSystem";
}

NavigatorEpubReadingSystem* NavigatorEpubReadingSystem::from(Navigator* navigator)
{
    NavigatorEpubReadingSystem* supplement = static_cast<NavigatorEpubReadingSystem*>(Supplement<Navigator>::from(navigator, supplementName()));
    if (!supplement) {
        supplement = new NavigatorEpubReadingSystem();
        provideTo(navigator, supplementName(), adoptPtr(supplement));
    }
    return supplement;
}

EpubReadingSystem* NavigatorEpubReadingSystem::epubReadingSystem(Navigator* navigator)
{
    return NavigatorEpubReadingSystem::from(navigator)->webkitEpubReadingSystem(navigator);
}

EpubReadingSystem* NavigatorEpubReadingSystem::webkitEpubReadingSystem(Navigator* navigator)
{
    if (!m_epubReadingSystem) {
        m_epubReadingSystem = EpubReadingSystem::create();
        navigator->frame()->loader()->client()->populateEpubReadingSystem(m_epubReadingSystem.get());
    }
    return m_epubReadingSystem.get();
}

} // namespace WebCore

#endif // ENABLE(EPUB3)
