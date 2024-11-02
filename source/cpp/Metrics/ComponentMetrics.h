class BaseComponentMetrics {
public:

	struct AvailabilityMetrics
	{
		double uptime_percentage;
		//mean time between failure
		double mtbf;
		//mean time to recovery
		double mttr;
		double availability_score;
	}
    
	struct PerformanceMetrics
	{
		double state_transition_rate;
		double average_time_in_operational;
		double remote_operation_percentage;
	}
	
	struct ReliabilityMetrics
	{
		int total_transitions;
		int unexpected_transitions;
		double transition_success_rate;
	}
	
	struct ModeMetrics
	{
		double local_mode_stability;
		double remote_mode_stability;
		double remote_standby_to_active_ratio;
	}
	
	struct TimeBasedMetrics
	{
		std::map<State, double> state_time_distribution;
		std::map<Mode, double> mode_time_distribution;
		std::map<SubMode, double> submode_time_distribution;
	}
	
	struct AvailabilityMetrics
	{
	}

    virtual ~BaseOperationalMetrics() = default;
    virtual void calculateMetrics(const std::vector<TimeWindow>& history,
                                const TimePoint& start,
                                const TimePoint& end) = 0;
};

class SystemMetrics {
public:

    struct SystemWideStatus
	{
		int total_active_components;
		int components_in_operational_state;
		double system_availability;
	}
    
	struct SynchronizationStatus
	{
		double component_state_sync_percentage;
		int conflicting_state_count;
	}
	
    struct LoadDistribution
	{
		// Load Distribution
		double remote_operation_load_balance;
		double maintenance_schedule_distribution;
	}
    
    struct SystemStability
	{
		double system_transition_rate;
		double system_state_stability;
    }
	
	struct CriticalPathAnalysis
	{
		std::vector<std::string> critical_path_components;
		double critical_path_availability;
	}
};