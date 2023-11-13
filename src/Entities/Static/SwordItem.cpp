#include "SwordItem.h"

SwordItem::SwordItem(int x, int y, shared_ptr<Handler> handler, ofImage sprite)
   : Item(x, y, handler, sprite) {
}
