# ArchViz VR/XR Project - Roadmap & Setup

## Overview
This project aims to build a C++-based ArchViz platform capable of:
- Importing 3D building models (Revit, ArchiCAD, Blender, FBX, glTF…)
- Rendering them with realistic lighting
- Allowing the user to walk around in VR/XR
- Interacting with doors, windows, lights, materials
- Eventually animating dynamic elements

## Required Skills

### A. C++ Skills
- Low-level memory management
- Smart pointers
- Object-oriented architecture
- Multithreading basics
- Working with C/C++ libraries
- CMake (CLion uses it by default)

### B. Graphics Programming
- GPU pipelines, coordinate systems
- Shaders (vertex, fragment)
- Lighting models (Phong, PBR)
- Basic rendering: meshes, textures, materials

### C. 3D File Processing
- Assimp (FBX, OBJ, many formats)
- tinygltf (recommended for modern workflows)
- Export formats from Revit / ArchiCAD

### D. VR / XR Development
- OpenXR concepts: views, projection layers, swapchains, tracking, controller inputs, frame loop

### E. Engine Architecture Concepts
- Scene graph, ECS
- Asset loading & caching
- Event system, input abstraction
- Physics integration (optional)

### F. Mathematics for Graphics
- Linear algebra: matrices, vectors
- Transformations: translate, rotate, scale
- Quaternions (VR tracking)

## Software & Libraries

### Development Tools
- CLion IDE
- CMake build system
- Xcode Command Line tools
- Homebrew
- Git

### Libraries
- OpenGL or Vulkan (graphics API)
- OpenXR (VR/XR)
- Assimp, tinygltf (3D import)
- GLM (math)
- stb_image (textures)
- Bullet Physics / PhysX (optional)
- RenderDoc (debugging)

### Optional Tools
- Blender (3D visualization & conversion)
- Revit / ArchiCAD Exporters
- Unreal Engine (for comparison/testing)

## Hardware
- Your 14-inch M4 MacBook (16GB RAM, 1TB storage) is sufficient
- VR headset recommended (choose one):
    - Meta Quest 3S (~€329)
    - HTC Vive XR Elite
    - Pico Neo 2 / Pico 4 (budget)

## Project Structure
```
/src
    /renderer
        shaders/
        textures/
        mesh/
        renderer.cpp/h
    /xr
        openxr_init.cpp
        xr_session.cpp
        xr_input.cpp
    /scene
        entity.cpp/h
        components/
    /import
        assimp_loader.cpp
        gltf_loader.cpp
    /core
        application.cpp
        window.cpp
        math/
        utils/
```

## Learning Roadmap
### Phase 1 — Foundation (2–4 weeks)
- Learn OpenGL/Vulkan basics
- Learn GLM (matrices, quaternions)
- Load simple model with Assimp
- Render a room with camera controls

### Phase 2 — VR Integration (1–2 months)
- Learn OpenXR
- Stereo rendering pipeline
- Head tracking, controller input
- Render simple cube in VR, implement navigation

### Phase 3 — ArchViz Features (2–6 months)
- Import full building models (FBX/glTF)
- Materials, textures, lighting
- Navigation (teleport/smooth locomotion)
- Basic interactions (doors, lights)
- UI inside VR

### Phase 4 — Optimization & Tools (ongoing)
- Shadows, GPU culling, light baking
- Asset optimization
- Multi-floor navigation

## AI Assistance
- Generate boilerplate code, CMake files
- Explain OpenXR/graphics functions
- Generate shaders
- Optimize rendering loops
- Convert pseudocode to C++

## Build Instructions (macOS)

```bash
# Install Xcode Command Line tools
xcode-select --install

# Install Homebrew
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install libraries
brew install cmake glm assimp openxr-sdk renderdoc
```

## First Milestone
- Render a simple cube in VR using OpenXR + OpenGL
