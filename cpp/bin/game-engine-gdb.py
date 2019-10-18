import gdb

class ColorPrinter(object):
    def __init__(self, val):
        self.val = val
    def to_string(self):
        return self.val["v"]

class PointPrinter(object):
    def __init__(self, val):
        self.val = val
    def to_string(self):
        return self.val["v"]["_M_elems"]

def build_pretty_printer():
    pp = gdb.printing.RegexpCollectionPrettyPrinter("GameEngine")
    pp.add_printer("Color", "^GameEngine::Graphics::Color$", ColorPrinter)
    pp.add_printer("Point", "^GameEngine::Math::Point<.*,.*>", PointPrinter)
    return pp

gdb.printing.register_pretty_printer(gdb.current_objfile(), build_pretty_printer())
