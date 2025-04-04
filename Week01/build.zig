const std = @import("std");

pub fn build(b: *std.Build) void {
    const optimize = b.standardOptimizeOption(.{});
    const target = b.standardTargetOptions(.{});

    const files = .{
        "3-1_Factorial.c",
        "3-2_Fibonacci.c",
        "3-3_Exponent.c",
        "4-2_Factorial_Iterative.c",
        "5-1_Hanoi.c",
        "5-2_Tree_Traversal.c",
        "7-1_Recursive_Array_Sum.c",
        "7-2_Recursive_Palindrome_Check.c",
        "Array_1D_01_Traversal.c",
        "Array_1D_02_Insertion.c",
        "Array_1D_03_Read.c",
        "Array_1D_04_Update.c",
        "Array_1D_05_Erase.c",
        "Array_1D_06_1_Student_Scores.c",
        "Array_1D_06_2_Inventory_System.c",
        "Factorial_Soal_1.c",
        "Factorial_Soal_2.c",
        "Factorial_Soal_3.c",
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
