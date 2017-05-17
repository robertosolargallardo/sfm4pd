TARGET=sfm4pd
CXXFLAGS=-Wall -g -lcurl -std=c++11 -O3
CXX=g++-4.9
OBJS=obj/sfm4pd.o obj/OSRMWrapper.o obj/Position.o obj/Pedestrian.o obj/Simulator.o obj/SRTM3Wrapper.o obj/Grid.o

$(TARGET):$(OBJS)
			 $(CXX) -o $@ $^ $(CXXFLAGS) 

obj/sfm4pd.o:src/sfm4pd.cc
				 $(CXX) $(CXXFLAGS) -c -o $@ $< 
obj/OSRMWrapper.o:src/OSRMWrapper.cc include/OSRMWrapper.h
				      $(CXX) $(CXXFLAGS) -c -o $@ $<
obj/SRTM3Wrapper.o:src/SRTM3Wrapper.cc include/SRTM3Wrapper.h
				      $(CXX) $(CXXFLAGS) -c -o $@ $<
obj/Position.o:src/Position.cc include/Position.h
				      $(CXX) $(CXXFLAGS) -c -o $@ $<
obj/Pedestrian.o:src/Pedestrian.cc include/Pedestrian.h
				     $(CXX) $(CXXFLAGS) -c -o $@ $<
obj/Simulator.o:src/Simulator.cc include/Simulator.h
				    $(CXX) $(CXXFLAGS) -c -o $@ $<
obj/Grid.o:src/Grid.cc include/Grid.h
			  $(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
		${RM} $(TARGET) $(OBJS)
			
