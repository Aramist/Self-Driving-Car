# CMake generated Testfile for 
# Source directory: /home/aramis/Desktop/Self-Driving-Car/ros_ws/src/cartographer
# Build directory: /home/aramis/Desktop/Self-Driving-Car/ros_ws/build_isolated/cartographer/install
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cartographer.sensor.compressed_point_cloud_test "cartographer.sensor.compressed_point_cloud_test")
add_test(cartographer.sensor.collator_test "cartographer.sensor.collator_test")
add_test(cartographer.sensor.voxel_filter_test "cartographer.sensor.voxel_filter_test")
add_test(cartographer.sensor.ordered_multi_queue_test "cartographer.sensor.ordered_multi_queue_test")
add_test(cartographer.sensor.point_cloud_test "cartographer.sensor.point_cloud_test")
add_test(cartographer.sensor.range_data_test "cartographer.sensor.range_data_test")
add_test(cartographer.mapping_3d.sparse_pose_graph.optimization_problem_test "cartographer.mapping_3d.sparse_pose_graph.optimization_problem_test")
add_test(cartographer.mapping_3d.motion_filter_test "cartographer.mapping_3d.motion_filter_test")
add_test(cartographer.mapping_3d.range_data_inserter_test "cartographer.mapping_3d.range_data_inserter_test")
add_test(cartographer.mapping_3d.kalman_local_trajectory_builder_test "cartographer.mapping_3d.kalman_local_trajectory_builder_test")
add_test(cartographer.mapping_3d.scan_matching.precomputation_grid_test "cartographer.mapping_3d.scan_matching.precomputation_grid_test")
add_test(cartographer.mapping_3d.scan_matching.fast_correlative_scan_matcher_test "cartographer.mapping_3d.scan_matching.fast_correlative_scan_matcher_test")
add_test(cartographer.mapping_3d.scan_matching.real_time_correlative_scan_matcher_test "cartographer.mapping_3d.scan_matching.real_time_correlative_scan_matcher_test")
add_test(cartographer.mapping_3d.scan_matching.interpolated_grid_test "cartographer.mapping_3d.scan_matching.interpolated_grid_test")
add_test(cartographer.mapping_3d.scan_matching.ceres_scan_matcher_test "cartographer.mapping_3d.scan_matching.ceres_scan_matcher_test")
add_test(cartographer.mapping_3d.hybrid_grid_test "cartographer.mapping_3d.hybrid_grid_test")
add_test(cartographer.common.lua_parameter_dictionary_test "cartographer.common.lua_parameter_dictionary_test")
add_test(cartographer.common.math_test "cartographer.common.math_test")
add_test(cartographer.common.fixed_ratio_sampler_test "cartographer.common.fixed_ratio_sampler_test")
add_test(cartographer.common.configuration_files_test "cartographer.common.configuration_files_test")
add_test(cartographer.common.blocking_queue_test "cartographer.common.blocking_queue_test")
add_test(cartographer.common.rate_timer_test "cartographer.common.rate_timer_test")
add_test(cartographer.transform.transform_test "cartographer.transform.transform_test")
add_test(cartographer.transform.transform_interpolation_buffer_test "cartographer.transform.transform_interpolation_buffer_test")
add_test(cartographer.kalman_filter.pose_tracker_test "cartographer.kalman_filter.pose_tracker_test")
add_test(cartographer.kalman_filter.gaussian_distribution_test "cartographer.kalman_filter.gaussian_distribution_test")
add_test(cartographer.kalman_filter.unscented_kalman_filter_test "cartographer.kalman_filter.unscented_kalman_filter_test")
add_test(cartographer.mapping_2d.xy_index_test "cartographer.mapping_2d.xy_index_test")
add_test(cartographer.mapping_2d.probability_grid_test "cartographer.mapping_2d.probability_grid_test")
add_test(cartographer.mapping_2d.range_data_inserter_test "cartographer.mapping_2d.range_data_inserter_test")
add_test(cartographer.mapping_2d.map_limits_test "cartographer.mapping_2d.map_limits_test")
add_test(cartographer.mapping_2d.submaps_test "cartographer.mapping_2d.submaps_test")
add_test(cartographer.mapping_2d.scan_matching.fast_correlative_scan_matcher_test "cartographer.mapping_2d.scan_matching.fast_correlative_scan_matcher_test")
add_test(cartographer.mapping_2d.scan_matching.real_time_correlative_scan_matcher_test "cartographer.mapping_2d.scan_matching.real_time_correlative_scan_matcher_test")
add_test(cartographer.mapping_2d.scan_matching.ceres_scan_matcher_test "cartographer.mapping_2d.scan_matching.ceres_scan_matcher_test")
add_test(cartographer.mapping_2d.scan_matching.correlative_scan_matcher_test "cartographer.mapping_2d.scan_matching.correlative_scan_matcher_test")
add_test(cartographer.mapping_2d.sparse_pose_graph_test "cartographer.mapping_2d.sparse_pose_graph_test")
add_test(cartographer.mapping.probability_values_test "cartographer.mapping.probability_values_test")
add_test(cartographer.mapping.pose_graph_trimmer_test "cartographer.mapping.pose_graph_trimmer_test")
add_test(cartographer.mapping.submaps_test "cartographer.mapping.submaps_test")
add_test(cartographer.mapping.trajectory_connectivity_test "cartographer.mapping.trajectory_connectivity_test")
add_test(cartographer.io.proto_stream_test "cartographer.io.proto_stream_test")
subdirs(gmock)
subdirs(docs)
