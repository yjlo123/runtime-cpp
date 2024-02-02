CXX = g++
CXXFLAGS = -std=c++11

SRCDIR = src
INCDIR = include
BUILDDIR = build
TARGET = runtime

SRCEXT = cpp
SOURCES = $(wildcard $(SRCDIR)/*.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c -o $@ $<

clean:
	rm -rf $(BUILDDIR)
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
