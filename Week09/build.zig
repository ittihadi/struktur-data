const std = @import("std");

pub fn build(b: *std.Build) void {
    const optimize = b.standardOptimizeOption(.{});
    const target = b.standardTargetOptions(.{});

    const files = .{
        "09_01_Traversal.c",
        "09_02_InsertBST.c",
        "09_03_DeleteBST.c",
        "09_04_PriceBasedItemCatalogue.c",
        "09_05_ScoreBasedStudentDatabase.c",
        "09_06_EComerceProductManagement.c",
        "09_07_FileTreeNavigation.c",
        "09_08_StudentDataManagement.c",
        "09_09_TicketOrderingSystem.c",
        "09_10_CodeBasedInventoryManagement.c",
        "09_11_PriceBasedItemCatalogueUpgrade.c",
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
