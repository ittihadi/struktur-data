const std = @import("std");

pub fn build(b: *std.Build) !void {
    const optimize = b.standardOptimizeOption(.{});
    const target = b.standardTargetOptions(.{});

    const build_all_step = b.step("all", "Builds all files");

    // Globs all .c files and compiles each individually
    var dir = try std.fs.cwd().openDir(".", .{.iterate = true});
    var it = dir.iterate();

    while (try it.next()) |file| {
        const ext = std.fs.path.extension(file.name);
        const basename = std.fs.path.basename(file.name);

        if(file.kind != .file or !std.mem.eql(u8, ext, ".c")) {
            continue;
        }

        const exe = b.addExecutable(.{
            .name = basename,
            .target = target,
            .optimize = optimize,
            .link_libc = true,
        });

        exe.addCSourceFile(.{ .file = b.path(file.name) });
        b.installArtifact(exe);

        build_all_step.dependOn(&exe.step);
    }
}
