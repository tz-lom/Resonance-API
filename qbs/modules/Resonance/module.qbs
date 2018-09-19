import qbs 1.0
import qbs.FileInfo
import qbs.ModUtils

Module {
    Depends { name: "cpp" }
    
    property bool headersOnly: false
    
    property path projectPath
    property path incPath: projectPath?(projectPath+'/include'):FileInfo.path(path+'/../../../include/')
    property path libPath: projectPath?(projectPath+'/bin'):FileInfo.path(path+'/../../../bin/')
    
    cpp.minimumOsxVersion: '10.9'

    cpp.includePaths: [incPath]
    cpp.libraryPaths: [libPath]
    cpp.dynamicLibraries: headersOnly?[]:['Resonance'];

    setupRunEnvironment: {
        var env;
        if (qbs.targetOS.contains('windows')) {
            env = new ModUtils.EnvironmentVariable("PATH", qbs.pathListSeparator, true);
            env.append(libPath);
            env.set();
        } else if (qbs.targetOS.contains("darwin")) {
            env = new ModUtils.EnvironmentVariable("DYLD_FRAMEWORK_PATH", qbs.pathListSeparator);
            env.append(libPath);
            env.set();

            env = new ModUtils.EnvironmentVariable("DYLD_LIBRARY_PATH", qbs.pathListSeparator);
            env.append(libPath);
            env.set();
        } else if (qbs.targetOS.contains('linux')) {
            env = new ModUtils.EnvironmentVariable("LD_LIBRARY_PATH", qbs.pathListSeparator);
            env.append(libPath);
            env.set();
        }
    }
    
}
