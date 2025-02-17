
#include "src/svg/svg_container.hpp"

#include <cassert>

namespace skity {

SVGContainer::SVGContainer(SVGTag tag) : SVGTransformableNode(tag) {}

void SVGContainer::AppendChild(std::shared_ptr<SVGNode> child) {
  assert(child != nullptr);
  children_.emplace_back(std::move(child));
}

void SVGContainer::OnRender(const SVGRenderContext& ctx) const {
  for (const auto& child : children_) {
    child->Render(ctx);
  }
}

Path SVGContainer::OnAsPath(const SVGRenderContext&) const {
  Path path;
  // TODO implement
  return path;
}

bool SVGContainer::HasChildren() const { return !children_.empty(); }

const char* SVGG::TagName() const { return "g"; }

std::shared_ptr<SVGG> SVGG::Make(const char* name) {
  if (std::strcmp(name, "g") == 0) {
    return std::make_shared<SVGG>();
  }

  return nullptr;
}

}  // namespace skity
