const std = @import("std");

pub fn build(b: *std.Build) void {
    const optimize = b.standardOptimizeOption(.{});
    const target = b.standardTargetOptions(.{});

    const files = .{
        "07_01_Operations.c",
        "07_02_Brace_Validation.c",
        "07_03_Infix_Convertion.c",
        "07_04_Undo_Redo.c",
        "08_01_Operations.c",
        "08_02_Postfix_Evaluation.c",
        "08_03_Backtracking_Sim.c",
        "08_04_Temporary_Data_Storage.c",
    };

    const build_all_step = b.step("all", "Builds all files");

    inline for (files) |file| {
        const exe = b.addExecutable(.{
            .name = file[0 .. file.len - 2],
            .target = target,
            .optimize = optimize,
            .link_libc = true,
        });

        exe.addCSourceFile(.{ .file = b.path(file) });
        b.installArtifact(exe);

        build_all_step.dependOn(&exe.step);
    }
}
